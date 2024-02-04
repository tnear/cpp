// Returns an iterator pointing to the first element in the range [first,last) which compares greater than val.
// https://cplusplus.com/reference/algorithm/upper_bound/
// ForwardIterator upper_bound(ForwardIterator first, ForwardIterator last, const T& val);
// O(lg n) algorithm

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

// lower_bound returns iterator to 1st elem NOT considered to go before VAL
// upper_bound returns iterator to 1st elem which goes after VAL
void upperBound()
{
    vector<int> v = {10, 20, 30, 40, 50, 60, 70};

    // '30' is first elem which does not go before 29
    auto itLow = std::lower_bound(v.begin(), v.end(), 29);
    assert(*itLow == 30);

    // '60' is first element which comes after 59
    auto itHigh = std::upper_bound(v.begin(), v.end(), 59);
    assert(*itHigh == 60);
}

void test()
{
    upperBound();
    // getIndex(); <-- see LowerBound.cpp for an example
    // customComparator <-- see LowerBound.cpp for an example
}

int main()
{
    test();

    std::cout << std::endl <<  __FILE__ " tests passed!" << std::endl;
    return 0;
}
