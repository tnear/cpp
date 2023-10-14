// Returns true if any element in the range [first,last) is equivalent to val, and false otherwise.
// https://cplusplus.com/reference/algorithm/binary_search/
// bool binary_search(ForwardIterator first, ForwardIterator last, const T& val);
// O(lg n) algorithm

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

void testBinarySearch()
{
    vector<int> v = {10, 20, 30, 40, 70, 80, 100};

    // found
    bool result = std::binary_search(v.begin(), v.end(), 30);
    assert(result);

    // not found
    result = std::binary_search(v.begin(), v.end(), -1);
    assert(!result);
}

void test()
{
    testBinarySearch();
}

int main()
{
    test();

    std::cout << std::endl <<  __FILE__ " tests passed!" << std::endl;
    return 0;
}
