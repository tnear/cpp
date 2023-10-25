/*
Flyweight string implements the flyweight software design pattern. It creates a pool of unique strings.
To compare strings, FlyweightString only needs to compare pointers yielding O(1) string comparison performance regardless of string size.
To create strings, FlyweightString much check if the string already exists in the string pool.
    - if so, return pointer to existing string in pool
    - if not, insert into pool then return new address

The performance numbers below show that FlyweightString string comparison beats std::string (tested using short strings which use the short string optimization).
However, the performance for FlyweightString's constructor is noticeably slower than std::string.

To get an idea as to when to use Flyweight over std::string, you can calculate how many string comparisons a program must make until Flyweight offers better performance.
Flyweight loses time for its constructor, but gains time when comparing:

FlyweightConstructor * 1 instance + FlyweightCompare * x == StringConstructor * 1 instance + StringCompare * x

...where 'x' is number of string comparisons to make.

>> solve(78.7 + 1.85*x == 7.02 + 8.63*x)
ans =

   10.5723

Flyweight offers better performance when doing 11 or more string comparisons.
Note: this result (11) is proportional to the string pool size

Conclusion:
- Prefer std::string by default as it is more portable and offers strong performance
- Prefer FlyweightString if you expect to do many (equal) string comparisons and few string creations
*/

static void StdString(benchmark::State &state)
{
    std::string m{"my_string"};
    std::string m2{"my_string"};
    for (auto _ : state)
    {
        bool equal = m == m2;
        benchmark::DoNotOptimize(equal);
    }
}

static void FlyweightString(benchmark::State &state)
{
    FlyweightString m{u"my_string"};
    FlyweightString m2{u"my_string"};
    for (auto _ : state)
    {
        bool equal = m == m2;
        benchmark::DoNotOptimize(equal);
    }
}

BENCHMARK(StdString);
BENCHMARK(FlyweightString);
BENCHMARK_MAIN();

/*
----------------------------------------------------
Benchmark           Time            CPU   Iterations
----------------------------------------------------
StdString        8.63 ns        8.54 ns     89600000
FlyweightString  1.85 ns        1.78 ns    448000000
*/


static void StdString(benchmark::State &state)
{
    for (auto _ : state)
    {
        std::string m{ "my_string" };
        benchmark::DoNotOptimize(m);
    }
}

static void FlyweightString(benchmark::State &state)
{
    for (auto _ : state)
    {
        FlyweightString m{ u"my_string" };
        benchmark::DoNotOptimize(m);
    }
}

/*
----------------------------------------------------
Benchmark           Time            CPU   Iterations
----------------------------------------------------
StdString        7.02 ns        7.11 ns    112000000
FlyweightString  78.7 ns        78.5 ns      8960000
*/
