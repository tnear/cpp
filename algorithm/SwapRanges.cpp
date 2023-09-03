//     Exchange values of two ranges
// https://cplusplus.com/reference/algorithm/swap_ranges/
// swap_ranges(ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2);

#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

void basic()
{
    vector<int> v1 = {10, 10, 10, 10};
    vector<int> v2 = {22, 22, 22, 22};

    // start swapping with the 2nd element in v1 and the first element in v2
    // stop swapping when reaching the 2nd to last element in v1
    std::swap_ranges(v1.begin() + 1, v1.end() - 1, v2.begin());

    vector<int> exp1 = {10, 22, 22, 10};
    vector<int> exp2 = {10, 10, 22, 22};
    assert(v1 == exp1);
    assert(v2 == exp2);
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
