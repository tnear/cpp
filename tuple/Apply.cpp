// std::apply unpacks as a tuple, unlike std::invoke which does not.

#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int sum(int x, int y)
{
    return x + y;
}

void testApply()
{
    tuple<int, int> tup = {3, 4};
    // calls sum with two integer arguments
    int ret = std::apply(sum, tup);
    assert(ret == 7);
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
