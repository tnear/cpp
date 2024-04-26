/*
https://en.cppreference.com/w/cpp/numeric/midpoint
std::midpoint (C++20) computes the midpoint without overflow.
Prefer std::midpoint over (a + b) / 2.
*/

#include <algorithm>
#include <cassert>
#include <functional>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

void mid()
{
    int result = std::midpoint(2, 5);
    assert(result == 3);

    // (-5 + -4) / 2 = -9 / 2 = -4.5. std::midpoint rounds toward the first argument
    result = midpoint(-5, -4);
    assert(result == -5);

    // regular division rounds -4.5 toward zero to produce -4 (not ideal for binary search)
    result = (-5 + -4) / 2;
    assert(result == -4);
}

void orderMatters()
{
    // midpoint rounds toward the *first* argument
    int result = midpoint(1, 4); // rounds 2.5 toward 1 to produce 2
    assert(result == 2);

    result = midpoint(4, 1); // rounds 2.5 toward 4 to produce 3
    assert(result == 3);

}

void test()
{
    mid();
    orderMatters();
}

int main()
{
    test();

    cout << endl <<  __FILE__ " tests passed!" << endl;
    return 0;
}
