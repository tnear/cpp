// Union of two sorted ranges
// https://cplusplus.com/reference/algorithm/set_union/
// OutputIterator set_union(InputIterator1 first1, InputIterator1 last1,
//                          InputIterator2 first2, InputIterator2 last2, OutputIterator result);

#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void basic()
{
    // std::set_union requires inputs be sorted
    vector<int> v1 = {2, 4, 5};
    vector<int> v2 = {5, 6, 7};

    vector<int> ret;

    // use back_inserter to push_back elements into ret
    // (without back_inserter, ret must be preallocated)
    std::set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), std::back_inserter(ret));

    // set_union returns a unique set of values in either container
    vector<int> exp = {2, 4, 5, 6, 7};
    assert(ret == exp);
}

void test()
{
    basic();
}

int main()
{
    test();

    std::cout << std::endl <<  __FILE__ " tests passed!" << std::endl;
    return 0;
}
