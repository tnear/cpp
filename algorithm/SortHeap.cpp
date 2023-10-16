// Sorts the elements in the heap range [first,last) into ascending order.
// https://cplusplus.com/reference/algorithm/sort_heap/
// void pop_heap(RandomAccessIterator first, RandomAccessIterator last);

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

void testBasic()
{
    vector<int> v1 = {1, 2, 3, 4, 5};
    
    // make a heap
    std::make_heap(v1.begin(), v1.end());
    assert(!is_sorted(v1.begin(), v1.end()));

    // calling sort_heap sorts heap (but loses heap property)
    std::sort_heap(v1.begin(), v1.end());

    assert(is_sorted(v1.begin(), v1.end()));
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
