// Returns an iterator to the first element in the partitioned range [first,last)
// for which pred is not true, indicating its partition point.
// https://cplusplus.com/reference/algorithm/partition_point/
// FwdIter partition_point(FwdIter first, FwdIter last, UnaryPredicate pred);

#include <algorithm>
#include <cassert>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

bool isOdd(int n)
{
    return n % 2;
}

void testVector()
{
    // create odd/even partition
    vector<int> v = {5, 3, 2, 6, 0, 4};
    //                        ^-- Partition point

    auto it = std::partition_point(v.begin(), v.end(), isOdd);
    assert(*it == 2);
}

void test()
{
    testVector();
}

int main()
{
    test();

    std::cout << std::endl <<  __FILE__ " tests passed!" << std::endl;
    return 0;
}
