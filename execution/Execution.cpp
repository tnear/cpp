/*
<execution> describes the execution policies for parallel algorithms.

*/

#include <algorithm>
#include <cassert>
#include <execution>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void policy()
{
    /*
    std::execution::seq       -> executes sequentially
    std::execution::seq       -> executes in parallel
    std::execution::par_unseq -> parallel without guaranteeing the order they are processed
                                 may use SIMD instructions and vectorization
    std::execution::unseq     -> algorithm may be vectorized in a single thread
                                 avoids race conditions due to being single-threaded
    */
}

void parallelSort()
{
    // use execution::par in <execution> to run an algorithm in parallel
    // note: ranges do not support execution policies as of C++20
    vector<int> data = {0, 4, 1, 2, 5, 3, 6};
    vector<int> exp = {0, 1, 2, 3, 4, 5, 6};
    std::sort(std::execution::par, data.begin(), data.end());
    assert(data == exp);
}

void test()
{
    policy();
    parallelSort();
}

int main()
{
    test();

    cout << endl <<  __FILE__ " tests passed!" << endl;
    return 0;
}
