/*
https://en.cppreference.com/w/cpp/algorithm/transform_reduce
transform_reduce (C++17) first transforms then reduces.
It is typically used with a parallel execution policy.
*/

#include <algorithm>
#include <cassert>
#include <execution>
#include <functional>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

void basic()
{
    vector<int> v = {1, 2, 3, 4, 5};

    // calculate the sum of squares in parallel
    int sumOfSquares = transform_reduce(
        execution::par, // parallel execution policy
        v.begin(), v.end(),
        0,                   // initial value for the reduction
        plus<int>(),    // reducing operation (sum)
        [](int x) { return x * x; } // transformation operation (square)
    );

    // sum(1 4 9 16 25) = 55
    assert(sumOfSquares == 55);
}

void test()
{
    basic();
}

int main()
{
    test();

    cout << endl
         << __FILE__ " tests passed!" << endl;
    return 0;
}
