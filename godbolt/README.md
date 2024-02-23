# Godbolt Compiler Explorer

## Registers
- Common registers (64-bit): `rax, rbx, rcx, rdx, rsp, rbp, rsi, rdi, r8-r15`
- Return register: `rax`
- Function arguments: `rdi (1st param), rsi (2nd param), rdx (3rd param)`
- Floating-point and SIMD registers (128-bit): `xmm0-xmm15`
- Floating-point and SIMD registers (256-bit): `ymm0-ymm15`
- Floating-point and SIMD registers (512-bit): `zmm0-zmm15`

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

## Dashboard
Dashboard showing site stats: [stats.compiler-explorer.com](stats.compiler-explorer.com).

Snapshot of 2024-02-20:
- C++: 3.2M
- C: 600K
- Rust: 187K
- Python: 57K
- Java: 32K
- CUDA: 26K
- Zig: 23K
- Assembly: 21K
- Haskell: 9K
- LLVM: 9K
- C#: 8K
- Go: 8K
