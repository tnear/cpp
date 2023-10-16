// Test if range is heap
// https://cplusplus.com/reference/algorithm/is_heap
// bool is_heap(RandomAccessIterator first, RandomAccessIterator last);

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

void testBasic()
{
    vector<int> v1 = {1, 2, 3, 4, 5};

    assert(!std::is_heap(v1.begin(), v1.end()));
    
    // make a heap
    std::make_heap(v1.begin(), v1.end());

    // verify it has heap property
    assert(std::is_heap(v1.begin(), v1.end()));
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
