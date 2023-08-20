// Returns the result of accumulating all the values in the range [first,last) to init.
// https://cplusplus.com/reference/numeric/accumulate/

#include <algorithm>
#include <cassert>
#include <functional>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

void sum()
{
    vector<int> v = {3, 4, 5};
    int init = 2;
    int result = std::accumulate(v.begin(), v.end(), init);

    // 2 (init) + 3 + 4 + 5 == 14
    assert(result == 14);
}

void multiply()
{
    vector<int> v = {2, 3, 4};

    int init = 1;
    int result = std::accumulate(v.begin(), v.end(), init, std::multiplies<int>());

    // 2 * 3 * 4 == 24
    assert(result = 24);
}

void test()
{
    sum();
    multiply();
}

int main()
{
    test();

    std::cout << std::endl <<  __FILE__ " tests passed!" << std::endl;
    return 0;
}
