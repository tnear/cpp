// Make max heap from range
// https://cplusplus.com/reference/algorithm/make_heap/
// void make_heap(RandomAccessIterator first, RandomAccessIterator last);

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

void testBasic()
{
    vector<int> v1 = {1, 2, 3, 4, 5};
    
    // make a max heap
    std::make_heap(v1.begin(), v1.end());

    vector<int> exp = {5, 4, 3, 1, 2};
    assert(v1 == exp);
}

void test()
{
    testBasic();
}

int main()
{
    test();

    std::cout << std::endl <<  __FILE__ " tests passed!" << std::endl;
    return 0;
}
