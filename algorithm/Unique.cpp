// Removes all but the first element from every consecutive group of equivalent elements in the range [first,last).
// https://cplusplus.com/reference/algorithm/unique/

#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// std::unique removes consecutive duplicates in a group
// It does not remove elements. Instead it returns an iterator to the new past-end-end element
void vec()
{
    vector<int> v = {1, 1, 2, 3, 3};
    auto it = std::unique(v.begin(), v.end());

    // it points to new past-the-end. after "removing" '1' and '3',
    // it points to the first 3:
    // {1, 1, 2, 3, 3} // orig vector
    // {1, 2, 3, u, u}
    //           ^-- it location

    assert(it == v.begin() + 3);

    // because unique does not remove, you must call erase to change the size
    assert(v.size() == 5);
    v.erase(it, v.end());

    vector<int> expV = {1, 2, 3};
    assert(v == expV);
}

void str()
{
    // data does not need to be sorted
    string s = "ccbaac";
    auto it = std::unique(s.begin(), s.end());
    assert(it == s.begin() + 4);
    s.erase(it, s.end());

    // note how duplicates can remain after calling std::unique (2 c's):
    assert(s == "cbac");
}

void test()
{
    vec();
    str();
}

int main()
{
    test();

    std::cout << std::endl <<  __FILE__ " tests passed!" << std::endl;
    return 0;
}
