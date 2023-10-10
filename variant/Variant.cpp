// Variant represents a type-safe union.
// https://en.cppreference.com/w/cpp/utility/variant

#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#include <variant>

using namespace std;

void constructor()
{
    // create variant with 3 types: int, string, double and construct with int
    variant<int, string, double> v { 60 };
    // verify int
    assert(v.index() == 0);
    assert(std::get<int>(v) == 60);

    // verify string
    v = "hello";
    assert(v.index() == 1);
    assert(std::get<string>(v) == "hello");

    // verify double
    v = 12.34;
    assert(v.index() == 2);
    assert(std::get<double>(v) == 12.34);
}

void test()
{
    constructor();
}

int main()
{
    test();

    std::cout << std::endl <<  __FILE__ " tests passed!" << std::endl;
    return 0;
}
