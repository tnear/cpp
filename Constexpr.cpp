// constexpr (constant expression)
// Indicates that a value is constant and, where possible, computed as compile time.
// constexpr debuted in C++11 then was expanded upon in future releases.

#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

void variables()
{
    // 'constexpr' is used like 'const' for variables
    constexpr double x = 3.1;
    static_assert(x == 3.1);

    // create new constexpr variable from existing
    constexpr double y = x + 1;
    static_assert(y == 4.1);
}

// a constexpr function is one whose return value can be computed
// at compile time when the call sites require it.
constexpr long int fib(int n)
{
    if (n <= 1)
        return n;

    return fib(n - 1) + fib(n - 2);
}

void functions()
{
    // compute fib() at compile time
    static_assert(fib(6) == 8);

    constexpr int n = 25;
    static_assert(fib(n) == 75025);
}

// 'constexpr if' to evaluate numeric vs non-numeric at compile time
template<typename T>
constexpr auto myLength(const T& value)
{
    if constexpr (std::is_integral<T>::value) // numeric types
        return value;
    else
        return value.length();
}

void constexprIf()
{
    // integer
    static_assert(myLength(5) == 5);

    // string
    static_assert(myLength(std::string{"abc"}) == 3);
}

void test()
{
    variables();
    functions();
    constexprIf();
}

int main()
{
    test();

    std::cout << std::endl <<  __FILE__ " tests passed!" << std::endl;
    return 0;
}
