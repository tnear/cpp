// Assigns to every element the difference between consecutive elements.
//   note: the first element of the result equals the first element of the input
// https://cplusplus.com/reference/numeric/adjacent_difference/

#include <algorithm>
#include <cassert>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

void basic()
{
    vector<int> v = {1, 1, 2, 3, 5, 8, 13};
    vector<int> result (v.size());

    std::adjacent_difference(v.begin(), v.end(), result.begin());

    // note: the first value of result equals the first value of input (1)
    // after than, the subsequent element equals the difference
    vector<int> expV = {1, 0, 1, 1, 2, 3, 5};
    assert(result == expV);
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
