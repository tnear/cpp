/*
std::numeric_limits queries properties of arithmetic types
https://cplusplus.com/reference/limits/numeric_limits/
*/

#include <cassert>
#include <cmath>
#include <iostream>
#include <limits>

using namespace std;

void maxTest()
{
    int i = std::numeric_limits<int>::max();
    assert(i == 2147483647);
    assert(i == INT_MAX);

    double d = std::numeric_limits<double>::max();
    assert(d == 1.7976931348623157e+308);
}

void minTest()
{
    // note how min() returns a negative result for int
    int i = std::numeric_limits<int>::min();
    assert(i == -2147483648);
    assert(i == INT_MIN);

    // ...but returns a positive result for double
    double d = std::numeric_limits<double>::min();
    assert(d == 2.2250738585072014e-308);

    // use lowest() to get the lowest negative number
    double lowest = numeric_limits<double>::lowest();
    assert(lowest < -1.7976e308);
}

void infinity()
{
    double limit = std::numeric_limits<double>::infinity();
    assert(std::isinf(limit));

    int intLimit = std::numeric_limits<int>::infinity();
    assert(intLimit == 0); // not defined for integers
}

void nanTest()
{
    double quietNan = std::numeric_limits<double>::quiet_NaN();
    assert(std::isnan(quietNan));
}

void test()
{
    maxTest();
    minTest();
    infinity();
    nanTest();
}

int main()
{
    test();

    std::cout << std::endl <<  __FILE__ " tests passed!" << std::endl;
    return 0;
}
