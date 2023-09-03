// Copies the elements in the range [first,last) for which pred returns true to the range beginning at result.
// https://cplusplus.com/reference/algorithm/copy_if/
// copy_if(InputIterator first, InputIterator last, OutputIterator result, UnaryPredicate pred);

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
    // std::set_difference requires inputs be sorted
    vector<int> v1 = {5, 3, 4, 2};
    vector<int> ret;

    // predicate gets all values > 3
    auto fcn = [] (const int value)
    {
        return value > 3;
    };

    std::copy_if(v1.begin(), v1.end(), std::back_inserter(ret), fcn);

    // only [5, 4] are greater than 3
    vector<int> exp = {5, 4};
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
