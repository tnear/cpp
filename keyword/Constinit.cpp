/*
constinit (C++20) asserts that a variable has static initialization,
i.e. zero initialization and constant initialization,
otherwise the program is ill-formed.

constinit is primarily used with global and static variables
to guarantee their initialization during compilation
https://en.cppreference.com/w/cpp/language/constinit
*/

#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

constinit int value { 10 };

void testConstinit()
{
    assert(value == 10);

    // with constinit, you can modify the value
    value = 100;
    assert(value == 100);
}

void test()
{
    testConstinit();
}

int main()
{
    test();

    std::cout << std::endl
              << __FILE__ " tests passed!" << std::endl;
    return 0;
}
