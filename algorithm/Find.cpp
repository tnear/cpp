// Returns an iterator to the first element in the range [first, last) that == val.
// https://cplusplus.com/reference/algorithm/find/
// std::find(InputIterator first, InputIterator last, const T& val)

#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// std::find does a linear scan using '==' to compare
void basic()
{
    vector<int> v = {1, 2, 3, 4, 5};

    // valid element
    auto it = std::find(v.begin(), v.end(), 4);
    assert(*it == 4);

    // invalid element
    it = std::find(v.begin(), v.end(), -1);
    assert(it == v.end());
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
