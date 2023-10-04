// Return iterator to lower bound
// O(lg n) algorithm
// https://cplusplus.com/reference/algorithm/lower_bound/
// lower_bound(ForwardIterator first, ForwardIterator last, const T& val);

#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

void basic()
{
    // std::lower_bound requires inputs to be sorted
    vector<int> v = {1, 2, 3, 4, 5, 7, 8};
    assert(std::is_sorted(v.begin(), v.end()));

    // returns is an iterator to first element in logarithmic time which does not compare < val
    auto it = std::lower_bound(v.begin(), v.end(), 3);

    // returns 3 because 3 is first element not less than 3
    assert(*it == 3);

    // search non-existent element (6). Returns 7.
    it = std::lower_bound(v.begin(), v.end(), 6);
    assert(*it == 7);

    // search smaller than min (-1), returns smallest element
    it = std::lower_bound(v.begin(), v.end(), -1);
    assert(*it == 1);
}

// example of using lower_bound to do binary search
void binarySearch()
{
    // create a vector with a missing element (2)
    vector<int> v = {1, 3, 4, 5, 6};

    // 2 is not in array, so lower_bound returns 1st elem which is not < val (3 in this case)
    auto it = std::lower_bound(v.begin(), v.end(), 2);
    cout << *it;
    bool found = *it == 2;
    assert(!found);
    assert(*it == 3);
}

void test()
{
    basic();
    binarySearch();
}

int main()
{
    test();

    std::cout << std::endl <<  __FILE__ " tests passed!" << std::endl;
    return 0;
}
