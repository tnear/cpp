// cmath -- a set of functions to compute common mathematical operations
// https://cplusplus.com/reference/cmath/

#include <cassert>
#include <iostream>
#include <cmath>

using namespace std;

void exponential()
{
    double result = exp(1);
    assert(result - 2.71828 < .0001);
}

void naturalLog()
{
    double result = log(exp(1));
    assert(result == 1);
}

void power()
{
    double result = pow(2, 6);
    assert(result == 64);
}

void squareRoot()
{
    double result = sqrt(2);
    assert(result - 1.414 < .001);
}

void quietNaN()
{
    double result = nan("");
    assert(isnan(result));
}

void test()
{
    exponential();
    naturalLog();
    power();
    squareRoot();
    quietNaN();
}

int main()
{
    test();

    std::cout << std::endl <<  __FILE__ " tests passed!" << std::endl;
    return 0;
}
