// Vectors are sequence containers representing arrays that can change in size.
// https://cplusplus.com/reference/vector/vector/

#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
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

    // initialize with specified value
    // create 5 elements each with value -1
    vector<int> v2(5, -1);
    expResult = {-1, -1, -1, -1, -1};
    assert(v2 == expResult);
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

void removeDuplicates()
{
    // see Unique.cpp for more info
    vector<int> v = {1, 1, 2, 3, 3};
    // use std::unique to move all non-duplicates to left
    auto it = std::unique(v.begin(), v.end());

    // because unique does not remove, you must call erase to change the size
    assert(v.size() == 5);
    v.erase(it, v.end());

    vector<int> expV = {1, 2, 3};
    assert(v == expV);

    // one-liner
    v = {1,1,2,3,3};
    v.erase(unique(v.begin(), v.end()), v.end());
    assert(v == expV);

    /*
    // erasing an end() iterator causes undefined behavior
    it = v.end();
    v.erase(it); // <-- crash
    assert(v == expV);
    */
}

void assign()
{
    // create a vector with duplicates
    vector<int> v = {1, 2, 3, 3, 4, 2, 1};
    // use a set to remove duplicates
    set<int> s = {v.begin(), v.end()};

    // use assign() to re-set vector. Can be used in place of constructor
    v.assign(s.begin(), s.end());

    vector<int> expV = {1, 2, 3, 4};
    assert(v == expV);
}

// Note: can use std::erase in C++20 for vector
void erase()
{
    vector<int> v = {4, 3, 2, 1, 0};

    // remove front (pop_front)
    v.erase(v.begin());
    vector<int> expV = {3, 2, 1, 0};
    assert(v == expV);

    // erase range (elems 3, 2, 1)
    v = {4, 3, 2, 1, 0};
    v.erase(v.begin() + 1, v.begin() + 4);
    expV = {4, 0};
    assert(v == expV);

    // remove all ones (one-liner)
    v = {2, 1, 1, 3, 1};
    v.erase(std::remove(v.begin(), v.end(), 1), v.end());
    expV = {2, 3};
    assert(v == expV);
}

// std::erase, defined in <vector>, C++20
void eraseCpp20()
{
    // erase all ones
    vector<int> v = {2, 1, 1, 3, 1};
    size_t numElemRemoved = std::erase(v, 1);
    assert(numElemRemoved == 3);
    vector<int> exp = {2, 3};
    assert(v == exp);

    // erase_if
    v = {2, 4, 1, 2, 3};

    // erase odd numbers
    std::erase_if(v, [] (int value) { return value % 2; });
    exp = {2, 4, 2};
    assert(v == exp);
}

void eraseIndex()
{
    // remove index=2 (value=3)
    vector<int> v = {1, 2, 3, 4};
    v.erase(v.begin() + 2);

    vector<int> exp = {1, 2, 4};
    assert(v == exp);
}

void findExample()
{
    vector<int> v = {4, 1, 0, 3, 2};

    // std::find does a linear search
    auto it = std::find(v.begin(), v.end(), 3);
    assert(*it == 3);

    it = std::find(v.begin(), v.end(), -1);
    assert(it == v.end());
}

void lowerBound()
{
    // lower_bound finds elements in O(lg n). It requires inputs to be sorted
    vector<int> v = {1, 2, 3, 4, 5, 7, 8};
    assert(std::is_sorted(v.begin(), v.end()));

    // return is an iterator to first element in O(lg n) which does not compare < val
    auto it = std::lower_bound(v.begin(), v.end(), 3);

    // returns 3 because 3 is first element not less than 3
    assert(*it == 3);
}

// there still isn't a clean, built-in way to do this as of C++20
string join(const vector<string> &input, char separator)
{
    string result;

    // iterate through strings
    for (const string &s : input)
    {
        result += s + separator;
    }

    // remove separator character from end
    result.erase(result.find_last_not_of(separator) + 1);

    return result;
}

void join()
{
    // join strings based on separator character
    vector<string> v = {"hello", "world", "test example"};
    char separator = ';';
    string result = join(v, separator);

    assert(result == "hello;world;test example");
}

// creates a subarray for v[begin:end] (end points one past end)
// similar syntax as python
template <typename T>
vector<T> indexing(const vector<T> vec, int start, int stop)
{
    // we know the resulting size, so preallocate
    vector<T> result(stop - start);

    // copy between indexes
    std::copy(vec.begin() + start, vec.begin() + stop, result.begin());
    return result;
}

void indexing()
{
    vector<int> v = {1, 2, 3, 4, 5};

    // get v[1:3] which equals {2, 3}
    vector<int> result = indexing(v, 1, 3);

    vector<int> exp = {2, 3};
    assert(result == exp);
}

void test()
{
    constructor();
    swap();
    insert();
    back();
    removeDuplicates();
    assign();
    erase();
    eraseCpp20();
    eraseIndex();
    findExample();
    lowerBound();
    join();
    indexing();
}

int main()
{
    test();

    std::cout << "\n" << __FILE__ " tests passed!" << std::endl;
    return 0;
}
