// Copy range of elements backward
// https://cplusplus.com/reference/algorithm/copy_backward/
// Iter2 copy_backward(Iter1 first, Iter1 last, Iter2 result);

#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// copy_backward is useful when the source and destination ranges overlap
// and the destination range starts inside the source range
void basic()
{
    vector<int> numbers = {10, 20, 30, 40, 50, -1, -1, -1};
    //              start --^            last --^  result --^

    // start = first elem to copy
    // last = one past last elem to copy
    // result = where range terminates

    // the new range ends at result, but where does it start?
    // (result - last) == 3, which means start+3 is where the new range starts (elem=40)
    // however, std::copy would first overwrite (40) with (10), so that when copying continues,
    // there would be a duplicate 10 at the end (incorrect)

    // copy_backward copies the LAST elem first and continues right to left
    // in other words, 50 shifts right 3, 40 shifts right 3, and so on, down to 10 (start)
    std::copy_backward(numbers.begin(), numbers.begin() + 5, numbers.end());

    vector<int> exp = {10, 20, 30, 10, 20, 30, 40, 50};
    assert(numbers == exp);
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

