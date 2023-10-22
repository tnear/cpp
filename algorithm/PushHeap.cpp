// Push element into max heap range
// https://cplusplus.com/reference/algorithm/push_heap/
// void push_heap(RandomAccessIterator first, RandomAccessIterator last);

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

    // use push_heap to maintain heap invariant after pushing data
    v1.push_back(10);
    std::push_heap(v1.begin(), v1.end());
    assert(v1.front() == 10);
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
