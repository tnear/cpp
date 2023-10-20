// Return the smallest and largest elements
// https://cplusplus.com/reference/algorithm/minmax/
// pair <const T&, const T&> minmax(const T& a, const T& b);

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

void testValue()
{
    // the smaller element goes in pair.first and larger in pair.second
    pair<int, int> result = std::minmax(-1, 2);
    assert(result.first == -1);
    assert(result.second == 2);
}

// C++11
void testInitializerList()
{
    // for initializer list, minmax returns the smallest and largest within the list
    pair<int, int> result = std::minmax({3, 2, 4, 1, 5});
    assert(result.first == 1);
    assert(result.second == 5);
}

void test()
{
    testValue();
    testInitializerList();
}

int main()
{
    test();

    std::cout << std::endl <<  __FILE__ " tests passed!" << std::endl;
    return 0;
}
