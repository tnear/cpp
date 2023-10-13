// Reverses the order of the elements in the range [first, last).
// https://cplusplus.com/reference/algorithm/reverse/
// void reverse(BidirectionalIterator first, BidirectionalIterator last);

#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void testString()
{
    string s = "abc";
    std::reverse(s.begin(), s.end());
    assert(s == "cba");
}

void testVector()
{
    vector<int> v = {1, 2, 3, 4};
    std::reverse(v.begin(), v.end());
    
    vector<int> exp = {4, 3, 2, 1};
    assert(v == exp);
}

void test()
{
    testString();
    testVector();
}

int main()
{
    test();

    std::cout << std::endl <<  __FILE__ " tests passed!" << std::endl;
    return 0;
}
