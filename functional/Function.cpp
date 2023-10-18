// std::function (C++11)
// Construct function wrapper
// https://cplusplus.com/reference/functional/function/function/

#include <cassert>
#include <functional>
#include <iostream>

using namespace std;

double adder(int x, int y)
{
    return x + y;
}

struct functor
{
    double operator()(int x, int y)
    {
        return x + y;
    }
};

struct Method
{
    double adder(int x, int y)
    {
        return x + y;
    }
};

void testFreeFunction()
{
    std::function<double(int, int)> fcn = adder;
    //      return -^     ^----^--- function args
    // this example returns a double and accepts two integers
    double result = fcn(5, 3);
    assert(result == 8);
}

void testFunctor()
{
    std::function<double(int, int)> fcn = functor();
    double result = fcn(5, 3);
    assert(result == 8);
}

void testLambda()
{
    std::function<double(int, int)> fcn = [](int x, int y) { return x + y; };
    double result = fcn(5, 3);
    assert(result == 8);
}

void test()
{
    testFreeFunction();
    testFunctor();
    testLambda();
}

int main()
{
    test();

    std::cout << std::endl <<  __FILE__ " tests passed!" << std::endl;
    return 0;
}
