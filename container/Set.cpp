// Sets are containers that store unique elements following a specific order.
// The implementation uses a balanced tree to achieve this.
// https://cplusplus.com/reference/set/set/

#include <algorithm>
#include <cassert>
#include <functional>
#include <iostream>
#include <string>
#include <set>
#include <vector>

using namespace std;

void constructor()
{
    // range constructor
    vector<int> v = {3, 1, 4, 2, 5};
    set<int> s { v.begin(), v.end() };
    assert(s.size() == 5);
}

void insert()
{
    set<int> s;
    s.insert(3);
    s.insert(2);
    s.insert(1);
    s.insert(4);

    // find 1
    assert(s.find(1) != s.end());

    // do not find -1
    assert(s.find(-1) == s.end());
}

void sorted()
{
    set<int> s;
    // insert out of order
    s.insert(3);
    s.insert(2);
    s.insert(1);
    s.insert(4);

    // set maintains sorted data, so iterating produces sorted results
    vector<int> results { s.begin(), s.end() };

    // verify sorted
    vector<int> expV = {1, 2, 3, 4};
    assert(results == expV);
}

void reverseSort()
{
    // use std::greater to create elements in descending order
    set<int, std::greater<int>> s;

    s.insert(3);
    s.insert(2);
    s.insert(1);
    s.insert(4);

    vector<int> results {s.begin(), s.end()};

    // verify descending order
    vector<int> expV = {4, 3, 2, 1};
    assert(results == expV);
}

void erase()
{
    set<int> s;
    s.insert(1);
    assert(s.count(1) == 1);

    // erase 1
    auto it = s.find(1);
    s.erase(it);

    // verify it is done
    assert(s.count(1) == 0);
    assert(s.empty());
}

void count()
{
    set<int> s;
    s.insert(5);

    assert(s.count(5) == 1);
    assert(s.count(-1) == 0);
}

// lower_bound returns iterator to 1st elem NOT considered to go before VAL
// upper_bound returns iterator to 1st elem which goes after VAL
void lowerBound()
{
    vector<int> v = {10, 20, 30, 40, 50, 60, 70};
    set<int> s { v.begin(), v.end() };

    // '30' is first elem which does not go before 29
    auto itLow = s.lower_bound(29);
    assert(*itLow == 30);

    // '60' is first element which comes after 59
    auto itHigh = s.upper_bound(59);
    assert(*itHigh == 60);

    // erase [30, 60). This removes [30, 40, 50]
    s.erase(itLow, itHigh);

    // verify new data after erasing
    vector<int> result { s.begin(), s.end() };
    vector<int> expV = {10, 20, 60, 70};
    assert(result == expV);
}

// Returns the bounds of a range that includes all the elements that are equivalent to val.
// Because all elements in a set are unique, the range returned will contain a single element at most.
// Return value:
//     pair.first  = lower_bound iterator
//     pair.second = upper_bound iterator
void equalRange()
{
    set<int> s;
    s.insert(1);
    s.insert(2);

    // equal_range on valid element
    auto itPair = s.equal_range(1);
    assert(*itPair.first == 1);
    assert(std::distance(itPair.first, itPair.second) == 1);
    assert(*itPair.second == 2);

    // equal_range on invalid element
    itPair = s.equal_range(-1);
    assert(std::distance(itPair.first, itPair.second) == 0);

    // first == begin b/c '1' is first element NOT < -1
    assert(itPair.first == s.begin());

    // second == begin b/c '1' is also first element which goes after -1
    assert(itPair.second == s.begin());
}

// C++17
// extract returns and removes an element
void extract()
{
    set<int> s = {4, 1, 6, 7};

    // extract 4
    auto result = s.extract(4);
    assert(result.value() == 4);
    
    // verify reduced size with '4' removed
    assert(s.size() == 3);
}

// C++17
// merge two sets
void merge()
{
    set<int> s = {1, 2, 3};
    set<int> s2 = {4, 5, 6, 7};

    // merge() moves (not copies) s2 into s1
    s.merge(s2);
    assert(s.size() == 7);
    assert(s2.empty()); // s2 gets emptied
}

void test()
{
    constructor();
    insert();
    sorted();
    reverseSort();
    erase();
    count();
    lowerBound();
    equalRange();
    extract();
    merge();
}

int main()
{
    test();

    std::cout << std::endl <<  __FILE__ " tests passed!" << std::endl;
    return 0;
}
