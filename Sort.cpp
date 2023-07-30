#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

void basic()
{
    // std::sort sorts ascending by default
    vector<int> v = {3, 2, 10, 1};
    std::sort(v.begin(), v.end());

    vector<int> expV = {1, 2, 3, 10};
    assert(v == expV);
}

void lambda()
{
    // use lambda function to sort descending
    // It returns TRUE when the lhs should go before rhs
    // ex: elem1 > elem2 says higher elements go on left, which is descending sort
    vector<int> v = {3, 2, 10, 1};
    std::sort(v.begin(), v.end(), [] (const auto &elem1, const auto &elem2) { return elem1 > elem2; });

    vector<int> expV = {10, 3, 2, 1};
    assert(v == expV);
}

void test()
{
    basic();
    lambda();
}

int main()
{
    test();

    std::cout << std::endl <<  __FILE__ " tests passed!" << std::endl;
    return 0;
}
