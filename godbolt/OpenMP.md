# OpenMP

Compile with `-fopenmp`.

## Matrix multiply
*https://godbolt.org/z/s5E7aTs7T*

This example compiles with `-O3 -fopenmp -std=c++23`.

Note the OMP-specific content such as `omp_outlined` and `__kmpc_fork_call`.

## Fibonacci
*https://godbolt.org/z/PWo74K1ax*

Note the calls to `call __kmpc_omp_task`, `__kmpc_omp_taskwait`, and `__kmpc_global_thread_num`.
