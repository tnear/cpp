// Searches the range [first, last) for the first occurrence of two consecutive elements that match.
// https://cplusplus.com/reference/algorithm/adjacent_find/
// adjacent_find(ForwardIter first, ForwardIter last, BinaryPredicate pred);

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
    vector<int> v = {1, 3, 2, 2, 4};

    // find first repeated element ('2')
    auto it = std::adjacent_find(v.begin(), v.end());

    // '2' is the first repeated element, iterator points to first 2
    assert(*it == 2);
    assert(it == v.begin() + 2);
}

void predicate()
{
    // use predicate to compare case insensitive
    auto compCaseInsensitive = [] (char c1, char c2)
    {
        return std::tolower(c1) == std::tolower(c2);
    };

    vector<char> v = {'a', 'b', 'B', 'a'};

    // find first repeated letter (ignoring case)
    auto it = std::adjacent_find(v.begin(), v.end(), compCaseInsensitive);

    // b/B is first repeat pair
    assert(*it == 'b');
    assert(it == v.begin() + 1);
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
