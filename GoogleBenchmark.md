# Google Benchmark

### Installation
- Download latest version of CMake
    - https://cmake.org/download/
- `git clone https://github.com/google/benchmark.git`
- `cd benchmark`
- `mkdir build && cd build`
- Generate Visual Studio (not vscode) solution:
    - `cmake -G "Visual Studio 17 2022" -DCMAKE_BUILD_TYPE=Release -DBENCHMARK_DOWNLOAD_DEPENDENCIES=ON ..`
- Open the generated solution and build in Visual Studio. Create both a release and debug build of `benchmark.lib`
- Create a new C++ Visual Studio project
- Add include directory to both release and debug configurations in your new project:
    - Go to Configuration Properties -> C/C++ -> General
    - In Additional Include Directories, add the path to the Google Benchmark include directory (e.g., the include folder inside the cloned benchmark repository)
- Configure linker options:
    - Linker -> General
    - In Additional Library Directories, add the path to the built Google Benchmark libraries (usually found in the build/src/{Release,Debug} directory)
    - Linker -> Input
    - Add `benchmark.lib` and `Shlwapi.lib`
        - See here for why Shlwapi: https://github.com/google/benchmark/issues/634
- Configure preprocessor options:
    - 'C/C++' -> 'Preprocessor' -> 'Preprocessor Definitions'
    - Add `BENCHMARK_STATIC_DEFINE`

With this configured, create a Google Benchmark file
```cpp
#include <benchmark/benchmark.h>

static void BM_SomeFunction(benchmark::State& state) {
  for (auto _ : state) {
    // code to benchmark
  }
}
BENCHMARK(BM_SomeFunction);
BENCHMARK_MAIN();
```
