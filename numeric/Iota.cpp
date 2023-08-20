// Store increasing sequence
// https://cplusplus.com/reference/numeric/iota/

#include <algorithm>
#include <cassert>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

void basic()
{
    // create vector of size 10
    vector<int> v(10);

    // create 1:10
    int init = 1;
    std::iota(v.begin(), v.end(), init);

    vector<int> expV = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    assert(v == expV);
}

void test()
{
    basic();
}

int main()
{
    test();

    std::cout << std::endl <<  __FILE__ " tests passed!" << std::endl;
    return 0;
}
