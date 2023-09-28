# Microsoft Visual C++

Microsoft Visual C++ (MSVC) is a compiler for the C family of languages. Its object name is `cl.exe`.

### Common flags
| Flag             | Description                                                                          |
|------------------|--------------------------------------------------------------------------------------|
| `/EHsc`          | Specifies the model of exception handling (C++ only).                                |
| `/Zi`            | Produces a program database (PDB) that contains type and debugging information.      |
| `/Fo<name>`      | Names the object file or DLL the linker creates.                                     |
| `/Fe<name>`      | Names the executable file or DLL the linker creates.                                 |
| `/nologo`        | Suppress startup banner (copyright and version information).                         |
| `-std=<standard>`| Specifies the language standard. Example: `cl.exe -std=c++20 filename.cpp`           |
| `/O2`            | Enables optimization for speed and creates the fastest possible code.                |
| `/WX`            | Treats all compiler warnings as errors.                                              |
| `/c`             | Compiles without linking.                                                            |
