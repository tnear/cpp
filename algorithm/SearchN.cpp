// Search range for subsequence
// https://cplusplus.com/reference/algorithm/search_n/
// search_n(ForwardIterator first, ForwardIterator last, Size count, const T& val);

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
    vector<int> data = {1, 2, 2, 3, 2, 2, 2, 4};

    // find 3 consecutive '2' values
    size_t sz = 3;
    int valueToFind = 2;
    auto it = std::search_n(data.begin(), data.end(), sz, valueToFind);

    // result points to the '2' at idx=4
    assert(it == data.begin() + 4);
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
