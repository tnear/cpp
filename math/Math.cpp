// Math.cpp

#include <cmath>
#include <cassert>
#include <iostream>

using namespace std;

// C++ does not have a native function for binomial coefficient, so use the recursive definition
int _nchoosek(int n, int k)
{
    if (k == 0)
        return 1;

    int subResult = _nchoosek(n - 1, k - 1);
    return n * subResult / k;
}

void nchoosek()
{
    int n = 52;
    int k = 3;

    int result = _nchoosek(52, 3);
    assert(result == 22100);
}

// this function overflows easily
int factorial(int n)
{
    int result = 1;
    for (int x = 1; x <= n; ++x)
    {
        result *= x;
    }

    return result;
}

// this function overflows easily
int catalan(int n)
{
    // equation for Catalan numbers:
    // c_n = (2n)! / ( (n+1)! * n! )

    int top = factorial(2 * n);
    int bottomLeft = factorial(n + 1);
    int bottomRight = factorial(n);

    int result = top / (bottomLeft * bottomRight);
    return result;
}

void testFactorial()
{
    int result = -1;
    result = factorial(0);
    assert(result == 1);
    result = factorial(1);
    assert(result == 1);
    result = factorial(5);
    assert(result == 120);
}

void testCatalan()
{
    // 1, 1, 2, 5, 14, 42, 132, 429, ...
    int result = 0;
    result = catalan(1);
    assert(result == 1);

    result = catalan(2);
    assert(result == 2);

    result = catalan(3);
    assert(result == 5);

    result = catalan(4);
    assert(result == 14);

    result = catalan(5);
    assert(result == 42);
}

void test()
{
    nchoosek();
    testFactorial();
    testCatalan();
}

int main()
{
    test();

    std::cout << std::endl <<  __FILE__ " tests passed!" << std::endl;
    return 0;
}
