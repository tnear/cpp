// Returns true if all elements match (ignoring order)
// https://cplusplus.com/reference/algorithm/is_permutation/
// bool is_permutation(ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2);

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
    vector<int> v1 = {1, 2, 3};
    vector<int> v2 = {2, 1, 3};

    bool isPermutation = std::is_permutation(v1.begin(), v1.end(), v2.begin());
    assert(isPermutation);

    v2 = {2, 1, 4};
    isPermutation = std::is_permutation(v1.begin(), v1.end(), v2.begin());
    assert(!isPermutation);
}

void str()
{
    string s1 = "abc";
    string s2 = "cab";

    assert(std::is_permutation(s1.begin(), s1.end(), s2.begin()));

    s2 = "qqq";
    assert(!std::is_permutation(s1.begin(), s1.end(), s2.begin()));
}

void test()
{
    basic();
    str();
}

int main()
{
    test();

    std::cout << std::endl <<  __FILE__ " tests passed!" << std::endl;
    return 0;
}
