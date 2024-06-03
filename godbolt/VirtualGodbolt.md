# Virtual Godbolt

See also [CRTP Goldbolt](CRTPGodbolt.md).

*https://godbolt.org/z/TPT1dcP34*

## Example

### CPP source
```cpp
class One
{
public:
    virtual int getNumber()
    {
        return 1;
    }
};

class Two : public One
{
public:
    int getNumber() override
    {
        return 2;
    }
};

// this returns 2 without needing a vtable
int noVirtualTable(bool isOne)
{
    One *base = new Two();
    return base->getNumber();
}

int vtable(bool isOne)
{
    One *base = nullptr;
    if (isOne)
        base = new One();
    else
        base = new Two();
    return base->getNumber();
}
```

### Assembly (Clang)
Interesting assembly notes:
- Even though `noVirtualTable` makes a virtual call, the compiler does not use the `vtable` because it always knows what the derived class will be.
- There are separate sections for the `vtable` for both `One` and `Two`.

```
noVirtualTable(bool):                    # @noVirtualTable(bool)
        mov     eax, 2
        ret
vtable(bool):                             # @vtable(bool)
        push    rbx
        mov     ebx, edi
        mov     edi, 8
        call    operator new(unsigned long)@PLT
        lea     rcx, [rip + vtable for One]
        lea     rdx, [rip + vtable for Two]
        test    ebx, ebx
        cmovne  rdx, rcx
        lea     rcx, [rip + vtable for One+16]
        lea     rsi, [rip + vtable for Two+16]
        cmovne  rsi, rcx
        mov     qword ptr [rax], rsi
        mov     rdi, rax
        pop     rbx
        jmp     qword ptr [rdx + 16]            # TAILCALL
Two::getNumber():                    # @Two::getNumber()
        mov     eax, 2
        ret
One::getNumber():                    # @One::getNumber()
        mov     eax, 1
        ret
vtable for Two:
        .quad   0
        .quad   typeinfo for Two
        .quad   Two::getNumber()

typeinfo name for Two:
        .asciz  "3Two"

typeinfo name for One:
        .asciz  "3One"

typeinfo for One:
        .quad   vtable for __cxxabiv1::__class_type_info+16
        .quad   typeinfo name for One

typeinfo for Two:
        .quad   vtable for __cxxabiv1::__si_class_type_info+16
        .quad   typeinfo name for Two
        .quad   typeinfo for One

vtable for One:
        .quad   0
        .quad   typeinfo for One
        .quad   One::getNumber()
```