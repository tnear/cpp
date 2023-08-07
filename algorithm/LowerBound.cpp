// Return iterator to lower bound
// https://cplusplus.com/reference/algorithm/lower_bound/

#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

void basic()
{
    // std::lower_bound requires inputs be sorted
    vector<int> v = {1, 2, 3, 4, 5, 7, 8};
    assert(std::is_sorted(v.begin(), v.end()));

    // return is an iterator to first element which does not compare < val
    auto it = std::lower_bound(v.begin(), v.end(), 3);
    
    // returns 3 b/c 3 is first element not less than 3
    assert(*it == 3);

    // search non-existent element (6). Returns 7.
    it = std::lower_bound(v.begin(), v.end(), 6);
    assert(*it == 7);

    // search smaller than min (-1), returns smallest element
    it = std::lower_bound(v.begin(), v.end(), -1); 
    assert(*it == 1);
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