// Variadic templates support a variable number of parameters.
// Variadic templates use parameter packs.

#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>

using namespace std;

// base case: one value
template <typename T>
T getSum(const T &t)
{
    return t;
}

// variadic case: use first then recursively call rest
template <typename First, typename... Rest>
First getSum(const First &first, const Rest &...rest)
{
    return first + getSum(rest...);
}

template <typename T, typename... Rest>
double getAverage(const T &first, const Rest &...rest)
{
    // average = sum / count
    T sum = getSum(first, rest...);
    size_t count = sizeof...(rest) + 1;

    return static_cast<double>(sum) / count;
}

void testInteger()
{
    int result = getSum(5);
    assert(result == 5);

    result = getSum(1, 2, 3, 4);
    assert(result == 10);
}

void testString()
{
    string s = getSum(string{"abc"});
    assert(s == "abc");

    s = getSum(string{"abc"}, string{"def"});
    assert(s == "abcdef");
}

void testAverage()
{
    double result = getAverage(1, 2, 3, 4);
    assert(result == 2.5);

    result = getAverage(-1, 1, -2, 2);
    assert(result == 0);
}

void test()
{
    testInteger();
    testString();
    testAverage();
}

int main()
{
    test();

    std::cout << std::endl
              << __FILE__ " tests passed!" << std::endl;
    return 0;
}
