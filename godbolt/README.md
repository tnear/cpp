# Godbolt Compiler Explorer

## Registers
- Common (64-bit) registers: `rax, rbx, rcx, rdx, rsp, rbp, rsi, rdi, r8-r15`
- Return register: `rax`
- Function arguments: `rdi, rsi, rdx`
- Floating-point registers: `xmm0-xmm15`

## Instructions

Assembly:
```asm
mov eax, DWORD PTR [r14]
add rax, rdi
add eax, DWORD PTR [r14+4]
sub eax, DWORD PTR [r14 + 4*rbx]
lea rax, [r14 + 4*rbx]            ; load effective address
xor edx, edx
```

Equivalent C/C++:
```cpp
int eax = *r14;
rax += rdi;
eas += r14[1];
eax -= r14[rbx]
int *rax = &r14[rbx];
edx = 0;
```
