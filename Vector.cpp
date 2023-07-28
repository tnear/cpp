// Vectors are sequence containers representing arrays that can change in size.
// https://cplusplus.com/reference/vector/vector/

#include <cassert>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

void constructor()
{
    unordered_set<int> s = {1, 2, 3, 4};

    // range constructor uses iterators and preallocates
    vector<int> v = {s.begin(), s.end()};

    vector<int> expResult = {1, 2, 3, 4};
    assert(v == expResult);
}

void swap()
{
    // O(1) to swap contents of vectors.
    // Exchanges data pointer
    vector<int> v1 = {1, 2, 3};
    vector<int> v2 = {4, 5};

    v1.swap(v2);

    vector<int> v1Exp = vector<int>{4, 5};
    vector<int> v2Exp = vector<int>{1, 2, 3};
    assert(v1 == v1Exp);
    assert(v2 == v2Exp);
}

void insert()
{
    // use v.insert() to insert at any location
    vector<int> v = {1, 2, 3};

    // insert at beginning to create [0, 1, 2, 3]
    v.insert(v.begin(), 0);
    assert(v[0] == 0);

    // insert after first element to create [0, 1, 10, 2, 3]
    v.insert(v.begin() + 2, 10);
    assert(v[2] == 10);
}

void back()
{
    // get last element value (not iterator)
    vector<int> v = {1, 2, 3};
    assert(v.back() == 3);

    // front() returns first element value
    assert(v.front() == 1);
}

void test()
{
    constructor();
    swap();
    insert();
    back();
}

int main()
{
    test();

    std::cout << "\n" << __FILE__ " tests passed!" << std::endl;
    return 0;
}
