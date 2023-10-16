// Intersection of two sorted ranges
// https://cplusplus.com/reference/algorithm/set_intersection/
// OutputIterator set_intersection (InputIterator1 first1, InputIterator1 last1,
//                                  InputIterator2 first2, InputIterator2 last2, OutputIterator result);


#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void basic()
{
    // std::set_intersection requires inputs be sorted
    vector<int> v1 = {2, 4, 5};
    vector<int> v2 = {4, 4, 5, 7};

    vector<int> ret;

    // use back_inserter to push_back elements into ret
    // (without back_inserter, ret must be preallocated)
    std::set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), std::back_inserter(ret));

    // set_intersection returns a unique set of values in both containers
    vector<int> exp = {4, 5};
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
