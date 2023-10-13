// Returns true if the range [first,last) is sorted into ascending order.
// https://cplusplus.com/reference/algorithm/is_sorted/
// bool is_sorted(ForwardIterator first, ForwardIterator last, Compare comp);

#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void testComparator()
{
    // descending sequence
    vector<int> v = {4, 3, 2, 1, 0};

    // using '>' instead of '<' to compare elements
    auto comparator = [&] (const int left, const int right) { return left > right; };

    assert(std::is_sorted(v.begin(), v.end(), comparator));
}

void test()
{
    testComparator();
}

int main()
{
    test();

    std::cout << std::endl <<  __FILE__ " tests passed!" << std::endl;
    return 0;
}
