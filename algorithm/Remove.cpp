// std::remove does NOT alter elements in a container. It only returns an iterator
// to the new end of the range. Calling std::remove is a 2-step process.
// to the new end of the range. Calling std::remove is a 2-step process.
// std::remove can only search values. To use a lambda expression, use remove_if instead.
// https://cplusplus.com/reference/algorithm/remove/

#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

void removeString()
{
    // remove all letter 'l' using std::remove + erase()
    // note: can only remove one letter using 'std::remove', not an entire string
    string s = "hello world";

    // find new end of string location
    auto it = std::remove(s.begin(), s.end(), 'l');

    // use 'erase' to modify the string
    s.erase(it, s.end());
    assert(s == "heo word");
}

void removeVector()
{
    vector<int> v = {2, 1, 3, 2, 4, 2};

    // remove all number '2' from vector
    auto it = std::remove(v.begin(), v.end(), 2);

    v.erase(it, v.end());

    vector<int> expVec = {1, 3, 4};
    assert(v == expVec);
}

void test()
{
    removeString();
    removeVector();
}

int main()
{
    test();

    std::cout << std::endl <<  __FILE__ " tests passed!" << std::endl;
    return 0;
}
