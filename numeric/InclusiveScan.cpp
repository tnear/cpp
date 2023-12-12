/*
Computes an inclusive prefix sum (cumsum) operation.
Input:  [3, 1, 4, 1,  5 , 9,  2,  6]
Output: [3, 4, 8, 9, 14, 23, 25, 31]
Defined in header <numeric>
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
    vector data = {3, 1, 4, 1, 5, 9, 2, 6};
    vector<int> result(data.size());

    // cumsum in MATLAB
    std::inclusive_scan(data.begin(), data.end(), result.begin());

    vector exp = {3, 4, 8, 9, 14, 23, 25, 31};
    assert(result == exp);
}

void test()
{
    testInclusiveScan();
}

int main()
{
    test();

    cout << endl <<  __FILE__ " tests passed!" << endl;
    return 0;
}
