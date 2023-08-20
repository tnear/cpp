// Like cumsum in MATLAB
// https://cplusplus.com/reference/numeric/partial_sum/

#include <algorithm>
#include <cassert>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

void cumsum()
{
    vector<int> v1 = {1, 2, 3, 4, 5};
    vector<int> v2 (v1.size());

    std::partial_sum(v1.begin(), v1.end(), v2.begin());

    vector<int> expV = {1, 3, 6, 10, 15};
    assert(v2 == expV);
}

void test()
{
    cumsum();
}

int main()
{
    test();

    std::cout << std::endl <<  __FILE__ " tests passed!" << std::endl;
    return 0;
}
