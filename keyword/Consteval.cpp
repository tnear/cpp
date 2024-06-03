/*
consteval (C++20) specifies that a function is an immediate function:
every call to the function *must* produce a compile-time constant

This is different from 'constexpr' which produces a compile-time
constant only when input data is known at compile time
https://en.cppreference.com/w/cpp/language/consteval
*/

#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

consteval int square(int n)
{
    return n * n;
}

// note: 'constexpr' instead of 'consteval' here causes a build error:
// 'square': call to immediate function is not a constant expression
consteval int doubleSquare(int n)
{
    return 2 * square(n);
}

void testConsteval()
{
    constexpr int result = square(9);
    static_assert(result == 81);

    constexpr int result2 = doubleSquare(5);
    static_assert(result2 == 50);
}

void test()
{
    testConsteval();
}

int main()
{
    test();

    std::cout << std::endl
              << __FILE__ " tests passed!" << std::endl;
    return 0;
}
