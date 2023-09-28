# Clang

Clang is a compiler front-end for the C family of languages.

### Common flags
| Flag             | Description                                                                                               |
|------------------|-----------------------------------------------------------------------------------------------------------|
| `-o <filename>`  | Specifies the output file name. Usage: `clang -o obj filename.c`                                          |
| `-std=<standard>`| Specifies the language standard. Example: `clang -std=c++20 filename.cpp`                                 |
| `-m32           `| Compile for 32-bit architecture                                                                           |
| `-Wall`          | Enables most warning messages.                                                                            |
| `-Wextra`        | Enables extra warning messages in addition to those enabled by `-Wall`.                                   |
| `-O0`            | No optimization (default). Speeds up compilation and includes debugging info.                             |
| `-O1`            | Enables basic optimizations without performing any loop optimizations.                                    |
| `-O2`            | Performs all optimizations that do not involve a space–speed tradeoff, including loop optimization.       |
| `-O3`            | Performs all `-O2` optimizations and others that may increase code size.                                  |
| `-g`             | Generates source-level debug information, including file names and line numbers.                          |
| `-c`             | Compiles source files to object files without linking.                                                    |

### Common usages
Windows:

`> clang -m32 -o obj.exe obj.cpp`

- m32 is needed due to my current Clang installation.
- `.exe` is recommended so that Windows knows its an executable.

Linux:

`$ clang -o obj.out obj.cpp`