// Rearranges the elements from the range [first,last), in such a way that all the
// elements for which pred returns true precede all those for which it returns false.
// The iterator returned points to the first element of the second group.
// https://cplusplus.com/reference/algorithm/partition/
// Iter partition (Iter first, Iter last, UnaryPredicate pred);

#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isOdd(int x)
{
    return x % 2;
}

void testVector()
{
    vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8};

    auto begin = v.begin(); // where to start partitioning (anything to the left is untouched)
    auto end = v.end();   // one past the last touched element (end is untouched)

    // the unary predicate groups elements which return TRUE on the left and FALSE on the right
    // therefore, the odd elements move left and even move right
    auto partitionPoint = std::partition(begin, end, isOdd);

    // std::partition creates:
    // [7, 1, 5, 3, 4, 2, 6, 0, 8]
    //              ^partitionPoint
    vector<int> expVec = {7, 1, 5, 3, 4, 2, 6, 0, 8};
    assert(v == expVec);
    assert(std::is_partitioned(v.begin(), v.end(), isOdd));

    // partition return value points to 1st elem in 2nd group where predicate returns FALSE
    // for this data, 2 is the first even number in the [begin, end) range
    assert(*partitionPoint == 4);
    assert(partitionPoint == v.begin() + 4);
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
