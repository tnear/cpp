// Rearranges the elements in the range [first,last), in such a way that the element at the
// nth position is the element that would be in that position in a sorted sequence.
// https://cplusplus.com/reference/algorithm/nth_element/
// void nth_element(RandomAccessIterator first, RandomAccessIterator nth, RandomAccessIterator last);
// O(n) algorithm (linear)

#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void testVector()
{
    vector<int> v = {4, 1, 3, 6, 5, 2};
    // sorted:      [1, 2, 3, 4, 5, 6]
    // N = 3                  ^-- N

    int N = 3;
    // nth_element will put the correct element (4) at index N
    std::nth_element(v.begin(), v.begin() + N, v.end());
    
    // the nth element is in the correct spot, but the entire array is not necessarily sorted
    assert(v[N] == 4);
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
