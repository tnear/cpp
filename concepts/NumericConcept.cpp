/*
Concepts perform compile-time validation of template arguments and
perform function dispatch based on properties of types.
https://en.cppreference.com/w/cpp/concepts
This example creates a 'Numeric' concept
*/

#include <algorithm>
#include <cassert>
#include <concepts>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ensure template arguments are numeric by defining this Numeric concept
// simple concepts do not need a 'requires' expression
template <typename T>
concept Numeric = std::is_arithmetic_v<T>;

// use Numeric in this templated function
template <Numeric T>
T Add(T a, T b)
{
    return a + b;
}

// Syntax for 2+ types, plus no 'concept' keyword
template <typename T>
requires std::integral<T> || std::floating_point<T>
T Add2(T a, T b)
{
    return a + b;
}

void numeric()
{
    double d = Add(2.5, 3.0);
    assert(d == 5.5);

    int i = Add(4, 5);
    assert(i == 9);

    // compilation error because Numeric<string> evaluates to false
    // string s = Add(string{"ab"}, string{"cd"});
}

void intOrFloat()
{
    double d = Add2(2.5, 3.0);
    assert(d == 5.5);

    int i = Add2(4, 5);
    assert(i == 9);
}

void test()
{
    numeric();
    intOrFloat();
}

int main()
{
    test();

    std::cout << std::endl <<  __FILE__ " tests passed!" << std::endl;
    return 0;
}
