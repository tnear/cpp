# EnumDataTypeBenchmark

Proof of concept to see how updating a C++98 enum to use C++11 enum class with data type impacts memory and performance. Timings are from Google Benchmark. The table shows clear cutoffs on different levels of cache are used.

Measurement results of allocating vector enum of int32 vs vector enum of uint8:
```
-----------------------------------------------------
Benchmark           Time             CPU   Iterations
-----------------------------------------------------
I32/8            60.9 ns         61.4 ns     11200000
I32/64           76.4 ns         75.3 ns      7466667
I32/512           206 ns          205 ns      3200000
I32/4096         1257 ns         1256 ns       497778
I32/32768       10062 ns        10010 ns        64000
I32/262144     519357 ns       515625 ns         1000
I8/8             59.3 ns         59.3 ns      8960000
I8/64            63.9 ns         62.8 ns      8960000
I8/512           74.4 ns         75.3 ns     11200000
I8/4096           103 ns          103 ns      5600000
I8/32768          831 ns          841 ns       836267
I8/262144       11002 ns        10986 ns        64000
```

The micro-benchmarks indicate that specifying a smaller enum data type (int8, for example, if one expects fewer than 2^8 = 256 enum values) saves memory and boosts performance.
