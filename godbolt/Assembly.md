# Assembly

## Registers
- Common registers (64-bit): `rax, rbx, rcx, rdx, rsp, rbp, rsi, rdi, r8-r15`
- Return register: `rax`
- Function arguments: `rdi (1st param), rsi (2nd param), rdx (3rd param)`
- Vector, floating-point, and SIMD registers
    - 128-bit: `xmm0-xmm15` (SSE registers)
    - 256-bit: `ymm0-ymm15` (AVX registers)
    - 512-bit: `zmm0-zmm15`

### Register order for syscalls:
```
$ man syscall

|Arch   |  arg1 | arg2 | arg3 | arg4 | arg5 | arg6 | arg7 |
|-------|-------|------|------|------|------|------|------|
|i386   | ebx   | ecx  | edx  | esi  | edi  | ebp  | -    |
|x86-64 | rdi   | rsi  | rdx  | r10  | r8   | r9   | -    |

Note: `rax` is set to the system call number.
```

### Calling convention
Registers are *shared* between functions, therefore must follow conventions about which registers are callee-saved and caller-saved.

### SIMD example
```
vmovdqu ymm2, YMMWORD PTR [rax] ; load 256-bits (32 bytes)
add rax, 32                     ; add 32 bytes (consumed by prev instruction)
vpmulld ymm0, ymm2, ymm2        ; square 32 bytes byte-wise
                                ; in one instruction (SIMD)
```

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

### Common instructions
| Instruction | Meaning                 |
|-------------|---------                |
| `movq`      | Move quadword (64 bits) |
| `cmov`      | Conditional move        |
| `movs`      | Move (sign extend)      |
| `movz`      | Move (zero extend)      |

### `movs`
When moving from a 32-bit register into 64-bit register, what happens to the higher bits? `movs` will fill those with zeros but preserve the sign (first bit).

## Displacement
```
movq 172(%rdi, %rdx, 8), %rax
           b     i   s     d
```
- b = base
- i = index
- s = scale (must be 1, 2, 4, or 8)
- d = displacement

This instruction performs `base + index * scale + displacement`.

