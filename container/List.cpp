// Lists are sequence containers that allow constant time insert and erase operations
// anywhere within the sequence, and iteration in both directions.
// https://cplusplus.com/reference/list/list/

#include <algorithm>
#include <cassert>
#include <functional>
#include <iostream>
#include <string>
#include <list>
#include <vector>

using namespace std;

void constructor()
{
    // create [0, 1, 2] using push_back and push_front
    list<int> data;
    data.push_back(1);
    data.push_back(2);
    data.push_front(0);

    vector<int> v { data.begin(), data.end() };

    vector<int> expV = {0, 1, 2};
    assert(v == expV);

    // range constructor
    list<int> data2 { v.begin(), v.end() };
    assert(data2.size() == 3);
}

// Lists have a sort method which runs in O(n lg n)
void sortList()
{
    list<int> data = {3, 1, 0, 4, 2};
    data.sort();

    // verify new order
    list<int> expData = {0, 1, 2, 3, 4};
    assert(data == expData);
}

// splice() transfers data from one list to another
// it changes the size of both lists
void splice()
{
    list<int> data1 = {1, 2, 3};
    list<int> data2 = {4, 5, 6};

    // get iterator to element=3
    auto it = data1.begin();
    ++it;
    ++it;
    assert(*it == 3);

    // splice data2 into data1 at value=3
    // this inserts {4, 5, 6} just before value=3 and removes them from data2
    data1.splice(it, data2);

    list<int> expData = {1, 2, 4, 5, 6, 3};
    assert(data1 == expData);
    assert(data1.size() == 6);
    assert(data2.empty());
}

// remove() changes the container size (unlike std::remove)
void removeList()
{
    list<int> data = {1, 2, 2, 1, 3};

    // remove all 1s from list
    data.remove(1);

    list<int> expData = {2, 2, 3};
    assert(data == expData);
}

// removes adjacent identical values
// unique() changes the container size (unlike std::unique)
void uniqueList()
{
    list<int> data = {3, 3, 1, 1, 1, 0};

    // remove all consecutive duplicates from the list
    data.unique();

    list<int> expData = {3, 1, 0};
    assert(data == expData);
}

void erase()
{
    list<int> data = {3, 4, 5, 6, 7};
    list<int> exp;

    // erase idx=2 element, [3, 4, *5*, 7, 7]
    auto it = data.begin();
    ++it; // note: linked list iterators do not have random access
    ++it;
    assert(*it == 5); // 'it' now points to 5
    data.erase(it);

    exp = {3, 4, 6, 7};
    assert(data == exp);
}

void test()
{
    constructor();
    sortList();
    splice();
    removeList();
    uniqueList();
    erase();
}

int main()
{
    test();

    std::cout << std::endl <<  __FILE__ " tests passed!" << std::endl;
    return 0;
}
