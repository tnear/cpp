// Rearranges the elements in the range [first,last), in such a way that the elements before
// middle are the smallest elements in the entire range and are sorted in ascending order,
// while the remaining elements are left without any specific order.
// https://cplusplus.com/reference/algorithm/partial_sort/
// void partial_sort(Iter first, Iter middle, Iter last, Compare comp);

#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void testVector()
{
    vector<int> v = {8, 6, 7, 9, 5, 4, 3, 2, 1};
    //                              ^-- Middle (begin+5)

    // use begin() + 5 to sort the lowest 6 elements
    // the last 3 elements are in an unspecified order
    std::partial_sort(v.begin(), v.begin() + 5, v.end());

    vector<int> exp = {1, 2, 3, 4, 5, 9, 8, 7, 6};
    assert(v == exp);
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
