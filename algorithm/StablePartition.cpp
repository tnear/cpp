// Rearranges the elements in the range [first, last), in such a way
// that all the elements for which pred returns true precede all
// those for which it returns false, and, unlike function partition,
// the relative order of elements within each group is preserved.
// https://cplusplus.com/reference/algorithm/stable_partition/
// stable_partition(BidirectionalIterator first, BidirectionalIterator last, UnaryPredicate pred);

#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

bool isOdd(int x)
{
    return x % 2;
}

// https://hackingcpp.com/cpp/std/algorithms.html#stable_partition
void seanParent()
{
    // [0  1  2  3  4  5  6  7  8]
    //        ^begin      ^end
    vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8};

    auto begin = v.begin() + 2; // where to start partitioning (anything to the left is untouched)
    auto end = v.begin() + 6;   // one past the last touched element (end is untouched)

    // the unary predicate groups elements which return TRUE on the left and FALSE on the right
    // therefore, the odd elements move left and even move right

    auto partitionPoint = std::stable_partition(begin, end, isOdd);

    // stable_partition creates:
    // [0  1  3  5  2  4  6  7  8]
    //              ^partitionPoint
    vector<int> expVec = {0, 1, 3, 5, 2, 4, 6, 7, 8};
    assert(v == expVec);

    // partition return value points to 1st elem in 2nd group where predicate returns FALSE
    // for this data, 2 is the first even number in the [begin, end) range
    assert(*partitionPoint == 2);
    assert(partitionPoint == v.begin() + 4);
}

void test()
{
    seanParent();
}

int main()
{
    test();

    std::cout << std::endl <<  __FILE__ " tests passed!" << std::endl;
    return 0;
}
