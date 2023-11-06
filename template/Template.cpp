/*
Notes and code samples using C++ templates.
*/

#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// C++ 20: templated function without the 'template' keyword
auto _doubler(auto &arg)
{
    return arg + arg;
}

void unconstrainedAuto()
{
    // C++20 allows:
    // void fcn(auto param)
    // instead of the more verbose:
    // template <typename T>
    // void fcn(T param)

    // to add constraints, use 'concept'

    // int example
    int x = 4;
    assert(_doubler(x) == 8);

    // string example
    string s = "ab";
    assert(_doubler(s) == "abab");
}

void test()
{
    unconstrainedAuto();
}

int main()
{
    test();

    std::cout << std::endl <<  __FILE__ " tests passed!" << std::endl;
    return 0;
}
