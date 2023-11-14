// Return the smallest
// https://cplusplus.com/reference/algorithm/min/
// const T& min(const T& a, const T& b);

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

void testValue()
{
    int result = std::min(-1, 2);
    assert(result == -1);

    result = std::min(3, 3);
    assert(result == 3);
}

struct MyData
{
    int a = 0;
    int b = 0;
};

void testComparator()
{
    auto fcn = [&] (const MyData &left, const MyData &right)
    {
        if (left.a < right.a)
            return true;

        return left.b <= right.b;
    };

    MyData left = {2, 3};
    MyData right = {2, 4};

    // use custom comparator for this class
    MyData result = std::min(left, right, fcn);
    assert(result.a == left.a && result.b == left.b);
}

// C++11
void testInitializerList()
{
    int num = 2;
    int result = std::min({3, num, 4, 1, 5});
    assert(result == 1);
}

void test()
{
    testValue();
    testComparator();
    testInitializerList();
}

int main()
{
    test();

    std::cout << std::endl <<  __FILE__ " tests passed!" << std::endl;
    return 0;
}
