/*
<utility>
https://cplusplus.com/reference/utility/pair/
 */

#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

void constructor()
{
    // default constructor
    std::pair<string, int> p1;
    assert(p1.first == "");
    assert(p1.second == 0);

    // value init constructor
    std::pair<string, int> p2 = {"hello", 1};
    assert(p2.first == "hello");
    assert(p2.second == 1);
}

void relationalOperators()
{
    // supported: ==, !=, <, >, <=, >=

    // create p1 < p2
    std::pair<int, double> p1 = {1, 2.0};
    std::pair<int, double> p2 = {2, 3.0};

    assert(p1 < p2);
}

void makePair()
{
    std::pair<int, int> p1;

    // braced initialization
    p1 = {2, 3};
    assert(p1 == std::make_pair(2, 3));

    // std::make_pair
    p1 = std::make_pair(2, 3);
    assert(p1 == std::make_pair(2, 3));
}

void test()
{
    constructor();
    relationalOperators();
    makePair();
}

int main()
{
    test();

    std::cout << std::endl << __FILE__ " tests passed!" << std::endl;
    return 0;
}
