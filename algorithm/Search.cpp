// Search range for subsequence
// https://cplusplus.com/reference/algorithm/search/
// bool search(ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2, ForwardIterator2 last2);

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
    vector<int> haystack = {1, 2, 3, 4, 5, 6};
    vector<int> needle = {3, 4, 5};

    // find {3, 4, 5} in {1, 2, 3, 4, 5, 6}
    auto it = std::search(haystack.begin(), haystack.end(), needle.begin(), needle.end());
    
    // the result points to elem=3 in the haystack container
    assert(it == haystack.begin() + 2);
    assert(*it == 3);
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
