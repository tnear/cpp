// Rotates the order of the elements in the range [first,last), in such a way
// that the element pointed by middle becomes the new first element.
// https://cplusplus.com/reference/algorithm/rotate/
// rotate(ForwardIterator first, ForwardIterator middle, ForwardIterator last);

#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// https://hackingcpp.com/cpp/std/algorithms/reordering.html#rotate
void seanParent()
{
    // [0  1  2  3  4  5  6  7  8]
    //  ^begin   ^newFirst   ^end
    vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8};

    auto begin = v.begin();        // where to start rotating (anything to the left is untouched)
    auto newFirst = v.begin() + 3; // the element which slides to 'begin'
    auto end = v.end() - 2;        // one past the last touched element (end is untouched)

    assert(*begin == 0);
    assert(*newFirst == 3);
    assert(*end == 7);

    auto newFirstLoc = std::rotate(begin, newFirst, end);

    // std::rotate creates:
    // [3  4  5  6  0  1  2  7  8]
    //              ^newFirst
    vector<int> expVec = {3, 4, 5, 6, 0, 1, 2, 7, 8};
    assert(v == expVec);

    // return value points to element which used to be the beginning
    assert(*newFirstLoc == 0);         // remains zero
    assert(newFirstLoc == v.begin() + 4); // moves location
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
