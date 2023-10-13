// Sorts elements and preserves relative order
// https://cplusplus.com/reference/algorithm/stable_sort/
// stable_sort(RandomAccessIterator first, RandomAccessIterator last, Compare comp);

#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void testVector()
{
    // std::stable_sort sorts ascending by default
    vector<int> v = {3, 2, 10, 2, 1, 4};
    std::sort(v.begin(), v.end());

    vector<int> expV = {1, 2, 2, 3, 4, 10};
    assert(v == expV);
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
