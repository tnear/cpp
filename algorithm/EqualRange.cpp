// Returns the bounds of the subrange that includes all the elements of the range [first,last) with values equivalent to val.
// https://cplusplus.com/reference/algorithm/equal_range/
// pair<ForwardIterator, ForwardIterator> equal_range(ForwardIterator first, ForwardIterator last, const T& val);
// O(lg n) algorithm

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

// lower_bound returns iterator to 1st elem NOT considered to go before VAL
// upper_bound returns iterator to 1st elem which goes after VAL
// equal_range requires range to be sorted.
void testEqualRange()
{
    const int value = 20;
    vector<int> v = {10, 10, 10, 20, 20, 20, 30, 30};
    //                      low -^            ^- high

    // the implementation of equal_range calls lower_bound() to get the low elem and
    /// upper_bound() to get the high element
    auto bounds = std::equal_range(v.begin(), v.end(), value);
    assert(bounds.first == v.begin() + 3);
    assert(bounds.second == v.begin() + 6);
    assert(*bounds.first == 20);
    assert(*bounds.second == 30);

    // show that equal range has same values as lower_bound
    auto lb = std::lower_bound(v.begin(), v.end(), value);
    assert(lb == bounds.first);

    // show that equal range has same values as upper_bound
    auto ub = std::upper_bound(v.begin(), v.end(), value);
    assert(ub == bounds.second);
}

void test()
{
    testEqualRange();
}

int main()
{
    test();

    std::cout << std::endl <<  __FILE__ " tests passed!" << std::endl;
    return 0;
}
