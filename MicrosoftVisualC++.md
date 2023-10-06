# Microsoft Visual C++

Microsoft Visual C++ (MSVC) is a compiler for the C family of languages. Its object name is `cl.exe`.

Compile file `Math.cpp` for `C++20` with PDB data and create an object file using `/Fo` named `Math.exe`:

### Debug build example
`cl.exe Math.cpp /Zi /EHsc /nologo /std:c++20 /FoMath`

### Release build example
`cl.exe Math.cpp /O2 /MT /EHsc /nologo /std:c++20 /FoMath`

### Common flags
| Flag             | Description                                                                          |
|------------------|--------------------------------------------------------------------------------------|
| `/Zi`            | Produces a program database (PDB) that contains type and debugging information.      |
| `/O2`            | Optimize for speed common for release builds.                                        |
| `/MT`            | Use the static version of the runtime library. Common for release builds.            |
| `/Fo<name>`      | Names the object file or DLL the linker creates.                                     |
| `/Fe<name>`      | Names the executable file or DLL the linker creates.                                 |
| `/EHsc`          | Specifies the model of exception handling (C++ only).                                |
| `/nologo`        | Suppress startup banner (copyright and version information).                         |
| `-std=<standard>`| Specifies the language standard. Example: `cl.exe -std=c++20 filename.cpp`           |
