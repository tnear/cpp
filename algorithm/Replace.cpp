// Exchange values of two ranges
// https://cplusplus.com/reference/algorithm/swap_ranges/
// swap_ranges(ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2);

#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

void replaceVector()
{
    vector<int> v = {1, 2, 3, 2, 1};

    // replace all 2 with 0
    std::replace(v.begin(), v.end(), 2, 0);

    vector<int> expV = {1, 0, 3, 0, 1};
    assert(v == expV);
}

// std::replace() in <algorithm> replaces one char with another (but not one string with another)
// (see replaceAll in String.cpp to see an example of that)
void replaceAllChar()
{
    string s = "hello world";

    // replace all 'l' with 'y'
    std::replace(s.begin(), s.end(), 'l', 'y');
    assert(s == "heyyo woryd");
}

void test()
{
    replaceVector();
    replaceAllChar();
}

int main()
{
    test();

    std::cout << std::endl <<  __FILE__ " tests passed!" << std::endl;
    return 0;
}
