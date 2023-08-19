// Multisets are containers that store elements following a specific order,
// and where multiple elements can have equivalent values.
// https://cplusplus.com/reference/set/multiset/

#include <algorithm>
#include <cassert>
#include <functional>
#include <iostream>
#include <string>
#include <set>
#include <vector>

using namespace std;

void insert()
{
    multiset<int> ms;
    // insert same value twice
    ms.insert(1);
    ms.insert(1);

    // verify double count (only possible with multiset)
    assert(ms.count(1) == 2);

    // erase first '1'
    auto it = ms.find(1);
    ms.erase(it);
    assert(ms.count(1) == 1);

    // erase second '1'
    it = ms.find(1);
    ms.erase(it);
    assert(ms.empty());
}

void equalRange()
{
    multiset<int> ms;
    // create [1, 2, 2, 3, 4]
    ms.insert(1);
    ms.insert(2);
    ms.insert(2);
    ms.insert(3);
    ms.insert(4);

    // equal_range on '2':
    auto itPair = ms.equal_range(2);
    // [1, 2, 2, 3, 4]
    //           ^-- upper_bound iterator for '2'
    //     ^-------- lower_bound iterator for '2'
    assert(std::distance(itPair.first, itPair.second) == 2);
    assert(*itPair.first == 2);
    assert(*itPair.second == 3);
}

void test()
{
    insert();
    equalRange();
}

int main()
{
    test();

    std::cout << std::endl <<  __FILE__ " tests passed!" << std::endl;
    return 0;
}
