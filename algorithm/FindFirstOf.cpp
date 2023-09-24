// Returns an iterator to the first element in the range1 that matches any of elements in range2
// https://cplusplus.com/reference/algorithm/find_first_of/
// find_first_of(InputIter first1, InputIter last1, FwdIter first2, FwdIter last2)

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
    vector<int> haystack = {1, 3, 6, 10, 11, 12};
    vector<int> needle = {2, 5, 10, 4};

    auto it = std::find_first_of(haystack.begin(), haystack.end(), needle.begin(), needle.end());

    // 10 is the first element in haystack which appears in needle
    assert(*it == 10);
    assert(it == haystack.begin() + 3);
}

void predicate()
{
    // can use a predicate when '==' is undesirable
    auto compCaseInsensitive = [] (char c1, char c2)
    {
        return std::tolower(c1) == std::tolower(c2);
    };

    vector<char> haystack = {'a', 'b', 'c', 'A', 'B', 'C'};
    vector<char> needle = {'A', 'B', 'C'};

    // find_first_of using case insensitive compare
    auto it = std::find_first_of(haystack.begin(), haystack.end(), needle.begin(), needle.end(), compCaseInsensitive);

    // the first element in haystack, 'a', matches the first element in needle, 'A' using insensitive compare
    assert(*it == 'a');
    assert(it == haystack.begin());
}

void test()
{
    basic();
    predicate();
}

int main()
{
    test();

    std::cout << std::endl <<  __FILE__ " tests passed!" << std::endl;
    return 0;
}
