// Compares elements with those in the range beginning at first2, and returns the first element of both sequences that does not match.
// https://cplusplus.com/reference/algorithm/mismatch/
// mismatch(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2);

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
    vector<int> v1 = {1, 2, 3, 4, 5};
    vector<int> v2 = {1, 2, 4, 5};

    // the two vectors mismatch at 3rd element
    auto pr = std::mismatch(v1.begin(), v1.end(), v2.begin());

    // pr is a pair of iterators, one for each of the two containers

    // pr.first points to '3' in v1
    assert(*pr.first == 3);
    assert(pr.first == v1.begin() + 2);

    // pr.second points to '4' in v2
    assert(*pr.second == 4);
    assert(pr.second == v2.begin() + 2);
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
