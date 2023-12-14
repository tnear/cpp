// Math.cpp

#include <cassert>
#include <iostream>

using namespace std;

// "binomial coefficient" aka "n choose k" aka "combinations" aka "nCk"
// order of elements does not matter for combinations (unlike permutations)
// C++ does not have a native function for binomial coefficient, so use the recursive definition
unsigned long long nchoosek(unsigned n, unsigned k)
{
    assert(k <= n);
    if (k == 0)
        return 1;

    unsigned long long subResult = nchoosek(n - 1, k - 1);
    return n * subResult / k;
}

// this function overflows easily
unsigned long long factorial(unsigned n)
{
    unsigned long long result = 1;
    for (unsigned x = 1; x <= n; ++x)
    {
        result *= x;
    }

    return result;
}

// aka nPk
// permutations = n! / (n - r)!
// where n = # items in set and r = # items taken
unsigned long long permutations(unsigned n, unsigned k)
{
    if (k > n)
        return 0; // no permutations if k is greater than n

    unsigned long long result = 1;

    for (unsigned i = 0; i < k; ++i)
        result *= (n - i);

    return result;
}

// equation for Catalan numbers:
// c_n = (2n)! / ( (n+1)! * n! )
// 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, 16796, 58786, ...
unsigned long long catalan(unsigned n)
{
    if (n <= 1)
        return 1;

    unsigned long long result = 1;

    for (unsigned int i = 0; i < n; ++i)
    {
        result *= (2 * n - i);
        result /= (i + 1);
    }

    return result / (n + 1);
}

void testNchoosek()
{
    assert(nchoosek(52, 3) == 22100);
    assert(nchoosek(5, 0) == 1);
    assert(nchoosek(16, 4) == 1820);
    assert(nchoosek(100'000, 100'000) == 1);
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
    assert(catalan(1) == 1);
    assert(catalan(2) == 2);
    assert(catalan(3) == 5);
    assert(catalan(4) == 14);
    assert(catalan(5) == 42);
    assert(catalan(6) == 132);
    assert(catalan(7) == 429);
    assert(catalan(8) == 1430);
    assert(catalan(9) == 4862);
    assert(catalan(10) == 16796);
    assert(catalan(11) == 58786);
}

void testPermutations()
{
    assert(permutations(4, 1) == 4);
    assert(permutations(6, 3) == 120);
    assert(permutations(6, 0) == 1);
    assert(permutations(4, 4) == 24);
    assert(permutations(4, 5) == 0);
}

void test()
{
    testNchoosek();
    testFactorial();
    testPermutations();
    testCatalan();
}

int main()
{
    test();

    std::cout << std::endl <<  __FILE__ " tests passed!" << std::endl;
    return 0;
}
