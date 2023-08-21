// Difference of two sorted ranges
// https://cplusplus.com/reference/algorithm/set_difference/
// set_difference(InputIter1 first1, InputIter1 last1, InputIter2 first2, InputIter2 last2, OutputIter result);

#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

void basic()
{
    // std::set_difference requires inputs be sorted
    vector<int> v1 = {2, 4, 5};
    vector<int> v2 = {5, 6, 7};

    vector<int> ret;

    // use back_inserter to push_back elements into ret
    // (without back_inserter, ret must be preallocated)
    std::set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), std::back_inserter(ret));

    // the values {2, 4} are in v1 but not v2:
    vector<int> exp = {2, 4};
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
