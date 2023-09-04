// Exchange values of two ranges
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
    vector<int> v = {1, 2, 3, 2, 1};

    // preallocate destination vector
    vector<int> destination(v.size());

    // copy from v to destination but replace all 2 in source with 0 in destination
    std::replace_copy(v.begin(), v.end(), destination.begin(), 2, 0);

    vector<int> expV = {1, 0, 3, 0, 1};
    assert(destination == expV);
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
