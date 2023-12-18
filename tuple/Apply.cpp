// std::apply unpacks as a tuple, unlike std::invoke which does not.
// C++17

#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int sum(int x, int y, int z)
{
    return x + y + z;
}

void testApply()
{
    tuple<int, int, int> tup = {3, 4, 5};
    // calls sum() using each tuple element as an argument
    int ret = std::apply(sum, tup);
    assert(ret == 12);
}

void test()
{
    testApply();
}

int main()
{
    test();

    std::cout << std::endl <<  __FILE__ " tests passed!" << std::endl;
    return 0;
}
