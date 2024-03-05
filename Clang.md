# Clang

Clang is a compiler front-end for the C family of languages.

## Debug build example

### Windows
`> clang++ Math.cpp -o Math.exe -g`

Note: `.exe` helps Windows to recognize an object file as an executable.

### Linux
`$ clang++ Math.cpp -o Math.o -g`

## Release build example
### Windows
`> clang++ Math.cpp -o Math.exe -O3`

### Linux
`$ clang++ Math.cpp -o Math.o -O3`

## Common compiler flags
| Flag             | Description                                                                                               |
|------------------|-----------------------------------------------------------------------------------------------------------|
| `-o <filename>`  | Specifies the output file name. Usage: `clang -o obj filename.c`                                          |
| `-std=<standard>`| Specifies the language standard. Example: `clang -std=c++20 filename.cpp`                                 |
| `-m32           `| Compile for 32-bit architecture                                                                           |
| `-O0`            | No optimization (default). Speeds up compilation and includes debugging info.                             |
| `-O1`            | Enables basic optimizations without performing any loop optimizations.                                    |
| `-O2`            | Performs all optimizations that do not involve a space–speed tradeoff, including loop optimization.       |
| `-O3`            | Performs all `-O2` optimizations and others that may increase code size.                                  |
| `-g`             | Generates source-level debug information, including file names and line numbers.                          |
| `-Wall`          | Enables most warning messages.                                                                            |
| `-Wextra`        | Enables extra warning messages in addition to those enabled by `-Wall`.                                   |
| `-S`             | Compiles source files to assembly files (output is assembly  plaintext file).                                                    |
| `-c`             | Compiles source files to object files without linking.                                                    |
| `-S -emit-llvm`  | Produce LLVM IR |
