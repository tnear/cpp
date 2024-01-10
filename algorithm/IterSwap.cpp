/*
Swaps the elements pointed to by a and b.
https://cplusplus.com/reference/algorithm/iter_swap/
void iter_swap(ForwardIterator1 a, ForwardIterator2 b);
Runtime: O(1)
*/

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

void iterSwap()
{
    vector<int> v = {1, 2, 3, 4, 5};
    //               1     2

    auto it1 = v.begin();
    auto it2 = v.begin() + 2;

    // swap elements (not iterators) 1 and 3.
    // this exchanges the values 1 and 3
    std::iter_swap(it1, it2);

    vector<int> exp = {3, 2, 1, 4, 5};
    assert(v == exp);
}

void test()
{
    iterSwap();
}

int main()
{
    test();

    std::cout << std::endl <<  __FILE__ " tests passed!" << std::endl;
    return 0;
}
