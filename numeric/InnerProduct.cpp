// Like dot product
// https://cplusplus.com/reference/numeric/inner_product/

#include <algorithm>
#include <cassert>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

void dotProduct()
{
    vector<int> v1 = {10, 20, 30};
    vector<int> v2 = { 1,  2,  3};

    // dot product
    int init = 0;
    int result = std::inner_product(v1.begin(), v1.end(), v2.begin(), init);

    // 10*1 + 20*2 + 30*3 = 10 + 40 + 90 = 140
    assert(result == 140);
}

void test()
{
    dotProduct();
}

int main()
{
    test();

    std::cout << std::endl <<  __FILE__ " tests passed!" << std::endl;
    return 0;
}
