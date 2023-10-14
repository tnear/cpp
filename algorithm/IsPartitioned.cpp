// Returns true if all the elements in the range [first,last) for which
// pred returns true precede those for which it returns false.
// https://cplusplus.com/reference/algorithm/is_partitioned/
// bool is_partitioned(InputIterator first, InputIterator last, UnaryPredicate pred);

#include <algorithm>
#include <cassert>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

bool isOdd(int n)
{
    return n % 2;
}

void testVector()
{
    // create non-partitioned vector
    vector<int> v = {1, 2, 3, 4};
    bool result = std::is_partitioned(v.begin(), v.end(), isOdd);
    assert(!result);

    // partition odd numbers on the left
    v = {1, 3, 4, 2};
    result = std::is_partitioned(v.begin(), v.end(), isOdd);
    assert(result);

    // partition odd numbers on the right
    // this is NOT partitioned because left elements must return true
    v = {4, 2, 3, 1};
    result = std::is_partitioned(v.begin(), v.end(), isOdd);
    assert(!result);
}

void test()
{
    testVector();
}

int main()
{
    test();

    std::cout << std::endl <<  __FILE__ " tests passed!" << std::endl;
    return 0;
}
