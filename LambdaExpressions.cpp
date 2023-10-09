// Lambda expressions

#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// C++14 introduced generalized lambda expressions
// which allow 'auto' function argument types
void generalizedLambda()
{
    auto plus = [](auto a, auto b) { return a + b; };

    // integer
    assert(plus(2, 3) == 5);

    // double
    assert(plus(1.5, 1.3) == 2.8);

    // string
    assert(plus(string{"ab"}, string{"cde"}) == "abcde");
}

// C++14
void defaultParameters()
{
    auto increment = [] (int x, int y = 1) { return x + y; };

    // use default argument
    assert(increment(10) == 11);

    // non-default argument
    assert(increment(10, 2) == 12);
}

// C++14 allowed returning lambda expressions using 'auto' return type
auto _getLambdaIncrement()
{
    auto fcn = [] (int value) { return value + 1; };
    return fcn;
}

void returnLambda()
{
    auto lambdaIncrement = _getLambdaIncrement();
    assert(lambdaIncrement(10) == 11);
}

// C++17 allowed lambda expressions to be constexpr
void constexprLambda()
{
    constexpr auto doubler = [] (int n) { return n + n; };
    static_assert(doubler(10) == 20);
}

void test()
{
    generalizedLambda();
    defaultParameters();
    returnLambda();
    constexprLambda();
}

int main()
{
    test();

    std::cout << std::endl
              << __FILE__ " tests passed!" << std::endl;
    return 0;
}
