// Returns an iterator to the first element in the range [first, last) for which pred returns true.
// https://cplusplus.com/reference/algorithm/find_if/
// std::find_if(InputIterator first, InputIterator last, UnaryPredicate pred)

#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// std::find_if does a linear scan and uses the predicate to compare
void basic()
{
    vector<int> v = {1, 2, 3, 4, 5};

    // predicate should return TRUE for matches
    auto findEven = [] (const auto &elem)
    {
        return elem % 2 == 0;
    };

    // find first even number in v
    auto it = std::find_if(v.begin(), v.end(), findEven);
    assert(*it == 2);
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
