// Return smallest element in range
// https://cplusplus.com/reference/algorithm/minmax_element/
// pair<FwdIter, FwdIter> minmax_element(FwdIter first, FwdIter last);

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

void testValue()
{
    vector<int> values = {2, 1, 3, 4, 5};
    auto it = std::minmax_element(values.begin(), values.end());

    assert(*it.first == 1);
    assert(*it.second == 5);
}

void test()
{
    testValue();
}

int main()
{
    test();

    std::cout << std::endl <<  __FILE__ " tests passed!" << std::endl;
    return 0;
}
