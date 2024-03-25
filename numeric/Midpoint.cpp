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

    // (-5 + -4) / 2 = -9 / 2 = -4.5. std::midpoint does floor:
    result = midpoint(-5, -4);
    assert(result == -5);

    // regular division rounds -4.5 toward zero to produce -4 (not ideal for binary search)
    result = (-5 + -4) / 2;
    assert(result == -4);
}

void test()
{
    mid();
}

int main()
{
    test();

    cout << endl <<  __FILE__ " tests passed!" << endl;
    return 0;
}
