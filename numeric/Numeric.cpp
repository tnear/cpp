// Numeric: a set of algorithms to perform operations on sequences of numeric values.

#include <algorithm>
#include <cassert>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

void testGcd()
{
    int result = std::gcd(12, 8);
    assert(result == 4);
}

void testLcm()
{
    int result = std::lcm(12, 8);
    assert(result == 24);
}

void test()
{
    testGcd();
    testLcm();
}

int main()
{
    test();

    std::cout << std::endl <<  __FILE__ " tests passed!" << std::endl;
    return 0;
}
