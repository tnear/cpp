/*
inclusive_scan (C++17): computes an inclusive prefix sum (cumsum in MATLAB).
Input:  [3, 1, 4, 1,  5 , 9,  2,  6]
Output: [3, 4, 8, 9, 14, 23, 25, 31]
Header: <numeric>
https://en.cppreference.com/w/cpp/algorithm/inclusive_scan
*/

#include <algorithm>
#include <cassert>
#include <deque>
#include <execution>
#include <functional>
#include <iostream>
#include <list>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

void testInclusiveScan()
{
    vector<int> data = {3, 1, 4, 1, 5, 9, 2, 6};
    vector<int> result(data.size());

    // cumsum in MATLAB
    std::inclusive_scan(data.begin(), data.end(), result.begin());

    vector exp = {3, 4, 8, 9, 14, 23, 25, 31};
    assert(result == exp);
}

void parallelInclusiveScan()
{
    vector<int> data = {2, 1, 3, 4, 0, -1};
    vector<int> result(data.size());

    inclusive_scan(execution::par, data.begin(), data.end(), result.begin());

    vector<int> exp = {2, 3, 6, 10, 10, 9};
    assert(result == exp);
}

void test()
{
    testInclusiveScan();
    parallelInclusiveScan();
}

int main()
{
    test();

    cout << endl <<  __FILE__ " tests passed!" << endl;
    return 0;
}
