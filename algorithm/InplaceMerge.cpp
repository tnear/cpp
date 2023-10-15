// Merges two consecutive sorted ranges: [first,middle) and [middle,last),
// putting the result into the combined sorted range [first,last).
// https://cplusplus.com/reference/algorithm/inplace_merge/
// void inplace_merge(BidirectionalIterator first, BidirectionalIterator middle, BidirectionalIterator last);

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

// use inplace_merge to merge ONE container which has two sorted ranges
// mid points to beginning of second sorted range within the one container
void testBasic()
{
    vector<int> v1 = {2, 3, 5, 6, 1, 3, 5, 7};
    //               {0, 1, 2, 3, 4, 5, 6, 7}
    //                            ^- merge mid point

    int midPoint = 4;
    std::inplace_merge(v1.begin(), v1.begin() + midPoint, v1.end());

    vector<int> exp = {1, 2, 3, 3, 5, 5, 6, 7};
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
