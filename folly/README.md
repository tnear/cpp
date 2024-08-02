# Facebook Folly

Repository: https://github.com/facebook/folly/

## `small_vector`
https://github.com/facebook/folly/blob/main/folly/docs/small_vector.md

`folly::small_vector` is a sequence container that implements small buffer optimization.

```cpp
small_vector<int, 2> v;
v.push_back(0); // stored on stack
v.push_back(1); // stored on stack
v.push_back(2); // allocates memory on heap
```

Note: insertion/reallocation is slow. If you need that to be fast, use `fbvector` instead.

## `FBVector`
https://github.com/facebook/folly/blob/main/folly/docs/FBVector.md

`folly::fbvector` is a documented replacement for `std::vector`. It uses a growth factor of 1.5 (instead of the older value of 2).

## `FBString`
https://github.com/facebook/folly/blob/main/folly/docs/FBString.md

`folly::fbstring` is a documented replacement for `std::string`. It uses a three-tiered storage strategy and cooperates with the memory allocator (such as jemalloc).

- Small string (<= 23 chars) are stored on the stack.
- Medium strings (24-255 chars) are stored in malloc-allocated memory and copied eagerly
- Large strings (>255 chars) are stored in malloc-allocated memory and copied lazily

### `find()`
The `find()` implementation for `fbstring` uses a simplified Boyer-Moore algorithm, which is typically over 1.5x faster than `std::string::find()`.

## `Benchmark`
https://github.com/facebook/folly/blob/main/folly/docs/Benchmark.md

`folly/Benchmark` is a framework for writing and executing benchmarks.

```cpp
#include <folly/Benchmark.h>
#include <vector>
using namespace std;
using namespace folly;
BENCHMARK(insertFrontVector) {
    // Let's insert 100 elements at the front of a vector
    vector<int> v;
    for (unsigned int i = 0; i < 100; ++i) {
        v.insert(v.begin(), i);
    }
}
BENCHMARK(insertBackVector) {
    // Let's insert 100 elements at the back of a vector
    vector<int> v;
    for (unsigned int i = 0; i < 100; ++i) {
        v.insert(v.end(), i);
    }
}
int main() {
    runBenchmarks();
}
```

Output:
```
===============================================
test.cpp              relative ns/iter  iters/s
===============================================
insertFrontVector                3.84K  260.38K
insertBackVector                 1.61K  622.75K
===============================================
```

### Baselines
To compare against a baseline, use the `BENCHMARK_RELATIVE` baseline macro. See documentation page for an example.

