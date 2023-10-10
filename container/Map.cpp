// Maps are associative containers that store elements formed by a combination
// of a key value and a mapped value, following a specific order.
// https://cplusplus.com/reference/map/map

#include <algorithm>
#include <cassert>
#include <functional>
#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

// lower_bound returns iterator to 1st elem NOT considered to go before VAL
// upper_bound returns iterator to 1st elem which goes after VAL
void lowerBoundUpperBound()
{
    map<int, int> m = { {10, 5}, {20, 4}, {30, 3}, {40, 2}, {50, 1}, {60, 0}, {70, -1} };

    // '30' is first elem which does not go before 29
    auto itLow = m.lower_bound(29);
    assert(itLow->first == 30);

    // '60' is first element which comes after 59
    auto itHigh = m.upper_bound(59);
    assert(itHigh->second == 60);
}

void test()
{
    lowerBoundUpperBound();
}

int main()
{
    test();

    std::cout << std::endl <<  __FILE__ " tests passed!" << std::endl;
    return 0;
}
