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

    vector<int> v;
    for (int elem : data)
        v.push_back(elem);

    vector<int> expV = {0, 1, 2};
    assert(v == expV);
}

// Lists have a sort method which runs in O (N lg N)
void sortList()
{
    list<int> data = {3, 1, 0, 4, 2};
    // sort
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
    // this inserts {4, 5, 6} just before value=3
    data1.splice(it, data2);

    list<int> expData = {1, 2, 4, 5, 6, 3};
    assert(data1 == expData);
    assert(data1.size() == 6);
    assert(data2.empty());
}

// list::remove changes the container size (unlike std::remove)
void removeList()
{
    list<int> data = {1, 2, 2, 1, 3};

    // remove all 1s from list
    data.remove(1);

    list<int> expData = {2, 2, 3};
    assert(data == expData);
}

// list::unique changes the container size (unlike std::unique)
void uniqueList()
{
    list<int> data = {2, 2, 1, 1, 1, 0};

    // remove all consecutive duplicates from the list
    data.unique();

    list<int> expData = {2, 1, 0};
    assert(data == expData);
}

void test()
{
    constructor();
    sortList();
    splice();
    removeList();
    uniqueList();
}

int main()
{
    test();

    std::cout << std::endl <<  __FILE__ " tests passed!" << std::endl;
    return 0;
}
