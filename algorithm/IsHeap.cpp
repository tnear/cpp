// Test if range is a max heap
// https://cplusplus.com/reference/algorithm/is_heap
// bool is_heap(RandomAccessIterator first, RandomAccessIterator last);

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

void isMaxHeap()
{
    vector<int> v1 = {1, 2, 3, 4, 5};

    assert(!std::is_heap(v1.begin(), v1.end()));
    
    // make a max heap
    std::make_heap(v1.begin(), v1.end());

    // verify it has max heap property
    assert(std::is_heap(v1.begin(), v1.end()));
    assert(v1[0] == 5);
}

void isMinHeap()
{
    vector<int> v = {2, 1, 3, 5, 4};

    // make a min heap by using '>' operator
    std::make_heap(v.begin(), v.end(), std::greater<>{});
    assert(std::is_heap(v.begin(), v.end(), std::greater<>{}));
    assert(v[0] == 1);
}

void test()
{
    isMaxHeap();
    isMinHeap();
}

int main()
{
    test();

    std::cout << std::endl <<  __FILE__ " tests passed!" << std::endl;
    return 0;
}
