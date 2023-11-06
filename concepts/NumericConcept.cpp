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

// syntax for 2+ types, plus no 'concept' keyword
// uses a 'requires' clause (see IterableConcept for a 'requires' expression)
template <typename T>
requires std::integral<T> || std::floating_point<T>
T AddNumeric(T a, T b)
{
    return a + b;
}

template <typename T>
concept Addable = requires (T a, T b)
{
    a + b; // Addable requires binary '+' operator
};

template <Addable T>
T AddAddable(T a, T b)
{
    return a + b;
}

void testNumeric()
{
    double d = Add(2.5, 3.0);
    assert(d == 5.5);

    int i = Add(4, 5);
    assert(i == 9);

    // compilation error because Numeric<string> evaluates to false
    // string s = Add(string{"ab"}, string{"cd"});
}

void testIntOrFloat()
{
    double d = AddNumeric(2.5, 3.0);
    assert(d == 5.5);

    int i = AddNumeric(4, 5);
    assert(i == 9);
}

void testAddable()
{
    // a + b sums a and b
    int a = 1, b = 2;
    int result = AddAddable(a, b);
    assert(result == 3);

    // s + t concatenates
    string s = "ab";
    string t = "cd";
    string str = AddAddable(s, t);
    assert(str == "abcd");

    // compilation fails with:
    // the concept 'Addable<nullptr>' evaluated to false
    // '+': illegal operand 'nullptr
    //AddAddable(nullptr, nullptr);
}

void test()
{
    testNumeric();
    testIntOrFloat();
    testAddable();
}

int main()
{
    test();

    std::cout << std::endl <<  __FILE__ " tests passed!" << std::endl;
    return 0;
}
