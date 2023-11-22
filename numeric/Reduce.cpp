// std::reduce applies an algorithm to a range of elements in an array
// By default, it return the sum of all elements in the range.
// reduce() is similar to accumulate(), but have differences:
//      - reduce supports parallel execution policies
//      - reduce requires commutative properties (ex: a * b = b * a)
//        This is because operations may be applied out of order
// std::reduce include: <numeric>

#include <algorithm>
#include <cassert>
#include <execution>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

// the default binary operator is std::plus<>()
// the binary operator for reduce() has two arguments:
// 1. the previous reduced value,
// 2. the new value
void testSum()
{
    vector<int> v = {1, 2, 3, 4};

    // default value of 0 (implicit)
    // note: there is no ranges::reduce support as of C++20
    int result = std::reduce(v.begin(), v.end());
    assert(result == 10);

    // default value of 5
    int defaultValue = 5;
    result = std::reduce(v.begin(), v.end(), defaultValue);
    assert(result == 15);
}

void testMultiply()
{
    vector<int> v = {1, 2, 3, 4};
    int defaultValue = 1;
    int result = reduce(v.begin(), v.end(), 1, std::multiplies<int>());
    assert(result == 24);
}

void testBinaryOp()
{
    vector<int> v = {1, 2, 3};

    // sum([idx[0] + 2 + idx[1] + 2 + idx[2] + 2 + ...)
    auto plusTwo = [] (int previousResult, int newNumber) { return previousResult + newNumber + 2; };
    int result = reduce(v.begin(), v.end(), 0, plusTwo);

    assert(result = 12);
}

void executionPolicy()
{
    // use an execution policy to run in parallel
    // note: reduce() supports this but accumulate() does not
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};
    int result = reduce(execution::par, v.begin(), v.end());
    assert(result == 36);
}

void test()
{
    testSum();
    testMultiply();
    testBinaryOp();
    executionPolicy();
}

int main()
{
    test();

    std::cout << std::endl <<  __FILE__ " tests passed!" << std::endl;
    return 0;
}
