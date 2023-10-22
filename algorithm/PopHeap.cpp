// Pop element from max heap range
// https://cplusplus.com/reference/algorithm/pop_heap/
// void pop_heap(RandomAccessIterator first, RandomAccessIterator last);

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

    // use pop_heap transforms the heap so that the last element can be
    // removed while maintaining the heap invariant
    std::pop_heap(v1.begin(), v1.end());
    v1.pop_back();

    assert(v1.front() == 4);
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
