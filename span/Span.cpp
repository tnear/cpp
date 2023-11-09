/*
A span (C++20) is a lightweight view of a contiguous sequence of values
https://en.cppreference.com/w/cpp/container/span
*/

#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <span>
#include <string>
#include <vector>

using namespace std;

void rangeFor()
{
    vector<int> v = {1, 2, 3, 4};
    span<int> s { v };

    // iterate over span use range for loop
    int idx = 1;
    for (int elem : s)
    {
        assert(elem == idx);
        ++idx;
    }
}

void beginEnd()
{
    vector<int> v = {1, 2, 3, 4};
    span<int> s { v };

    assert(*s.begin() == 1);
    assert(*(s.end() - 1) == 4);
}

void data()
{
    vector<int> v = {1, 2, 3, 4};
    span<int> s { v };

    // use data() to get a raw pointer
    assert(s.data() == v.data());
}

void arrayTest()
{
    // spans work with std::array and c-style array
    std::array<int, 3> arr = {1, 2, 3};
    span<int> s1 { arr };
    assert(s1.front() == 1);

    int cArray[3] = {4, 5, 6};
    span<int> s2 { cArray };
    assert(s2.back() == 6);
}

void empty()
{
    // default construct creates an empty span
    span<int> s;
    assert(s.empty());

    // assignment to empty creates an empty span
    vector<int> v = {};
    s = v;
    assert(s.empty());

    // assignment to non-empty creates a non-empty span
    v = {1};
    s = v;
    assert(!s.empty());
}

void firstLast()
{
    // use first() to get the first N elements
    vector<int> v = {3, 4, 5};
    span<int> s =  v;

    span<int> subspan = s.first(2);
    assert(subspan.size() == 2);
    assert(subspan[0] == 3);
    assert(subspan[1] == 4);

    // use last() to get the last N elements
    subspan = s.last(2);
    assert(subspan.size() == 2);
    assert(subspan[0] == 4);
    assert(subspan[1] == 5);
}

void test()
{
    rangeFor();
    beginEnd();
    data();
    arrayTest();
    empty();
    firstLast();
}

int main()
{
    test();

    std::cout << std::endl <<  __FILE__ " tests passed!" << std::endl;
    return 0;
}
