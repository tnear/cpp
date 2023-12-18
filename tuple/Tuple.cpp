/*
<tuple>
https://cplusplus.com/reference/tuple/tuple/
A tuple is an object capable to hold a collection of elements.
Each element can be of a different type.
*/

#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

void constructor()
{
    // default constructor
    std::tuple<string, int, double> t;
    assert(std::get<0>(t) == "");
    assert(std::get<1>(t) == 0);
    assert(std::get<2>(t) == 0.0);

    // value init constructor
    std::tuple<string, int, double> t2 = {"hello", 1, 2.2};
    assert(std::get<0>(t2) == "hello");
    assert(std::get<1>(t2) == 1);
    assert(std::get<2>(t2) == 2.2);
}

void tieFunction()
{
    std::tuple<int, bool, char> tup = {2, true, 'c'};

    // unpack elements using structured binding (C++17) [std::tie is alternative syntax]
    auto [x, y, z] = tup;
    assert(x == 2);
    assert(y == true);
    assert(z == 'c');
}

void reassign()
{
    std::tuple<int, bool, char> tup = {2, true, 'c'};

    // change/modify values after tuple has been initialized (std::get returns a reference)
    std::get<0>(tup) = 1;
    std::get<1>(tup) = false;
    std::get<2>(tup) = 'a';

    assert(std::get<0>(tup) == 1);
    assert(std::get<1>(tup) == false);
    assert(std::get<2>(tup) == 'a');
}

void test()
{
    constructor();
    tieFunction();
    reassign();
}

int main()
{
    test();

    std::cout << std::endl << __FILE__ " tests passed!" << std::endl;
    return 0;
}
