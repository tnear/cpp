// Copies the elements in the range [first, last) into the range beginning at result.
// https://cplusplus.com/reference/algorithm/copy/
// copy(InputIterator first, InputIterator last, OutputIterator result);

#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

void basic()
{
    vector<int> input = {1, 2, 3};
    // preallocate output
    vector<int> output(input.size());

    // copy from input to output
    std::copy(input.begin(), input.end(), output.begin());
    
    assert(input == output);
}

// copy doesn't need to use same container for input/output
// be careful about copying overlapping ranges (see copy_backward)
void sameContainer()
{
    vector<int> data = {1, 2, 3, 4, 5};

    // copy [1, 2] over [4, 5]
    std::copy(data.begin(), data.begin() + 2, data.end() - 2);

    // this creates [1, 2, 3, 1, 2]
    vector<int> expV = {1, 2, 3, 1, 2};
    assert(data == expV);
}

void test()
{
    basic();
    sameContainer();
}

int main()
{
    test();

    std::cout << std::endl <<  __FILE__ " tests passed!" << std::endl;
    return 0;
}
