// Checks if ranges of elements are equal
// https://cplusplus.com/reference/algorithm/equal/
// bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2);

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
    // create two vectors equal only for the first four elements
    vector<int> v1 = {1, 2, 3, 4, 5};
    vector<int> v2 = {1, 2, 3, 4};

    // assert that the first 4 elements in v1 and v2 are equal
    bool result = std::equal(v1.begin(), v1.begin() + 3, v2.begin());
    assert(result);

    // assert that the entire vectors are not equal
    result = std::equal(v1.begin(), v1.end(), v2.begin());
    assert(!result);
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
