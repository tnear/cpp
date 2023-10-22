// Test if range is max heap
// https://cplusplus.com/reference/algorithm/is_heap_until/
// RandomAccessIterator is_heap_until(RandomAccessIterator first, RandomAccessIterator last);

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

    // break heap property
    // changing front makes -10 a heap and everything after not
    v1.front() = -10;

    // v1 = {-10, 4, 3, 1, 2}
    //  heap -^   ^- not heap anymore
    auto it = std::is_heap_until(v1.begin(), v1.end());
    assert(*it == 4);
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
