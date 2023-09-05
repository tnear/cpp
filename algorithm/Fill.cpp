// Assigns val to all the elements in the range [first,last).
// https://cplusplus.com/reference/algorithm/fill/
// void fill(ForwardIterator first, ForwardIterator last, const T& val);

#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void basic()
{
    // create [0, 0, 0, 0]
    vector<int> v(4);

    // fill vector with 3s to create [3, 3, 3, 3]
    std::fill(v.begin(), v.end(), 3);

    vector<int> expV = {3, 3, 3, 3};
    assert(v == expV);
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
