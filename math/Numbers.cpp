/*
<numbers> (C++20) provides mathematical constants
*/

#include <cassert>
#include <iostream>
#include <numbers>

using namespace std;

void basic()
{
    // in double precision numbers,
    //    pi = 3.141592653589793
    //     e = 2.718281828459045
    // sqrt2 = 1.4142135623730951
    static_assert(std::numbers::pi - 3.14159265358979 < .00000000000001);
    static_assert(std::numbers::e - 2.71828182 < .00000001);
    static_assert(std::numbers::sqrt2 - 1.414 < .001);
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
