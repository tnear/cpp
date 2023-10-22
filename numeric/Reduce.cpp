// std::reduce applies an algorithm to a range of elements in an array
// By default, it return the sum of all elements in the range.
// reduce() is similar to accumulate(), but have differences:
//      - reduce supports parallel execution policies
//      - reduce requires commutative properties (ex: a * b = b * a)
//        This is because operations may be applied out of order
// <numeric>

#include <algorithm>
#include <cassert>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

void testSum()
{
    vector<int> v = {1, 2, 3, 4};

    // default value of 0 (implicit)
    int result = std::reduce(v.begin(), v.end());
    assert(result == 10);

    // default value of 5
    result = std::reduce(v.begin(), v.end(), 5);
    assert(result == 15);
}

void test()
{
    testSum();
}

int main()
{
    test();

    std::cout << std::endl <<  __FILE__ " tests passed!" << std::endl;
    return 0;
}
