// Assigns val to all the elements in the range [first,last).
// https://cplusplus.com/reference/algorithm/fill/
// void generate(ForwardIterator first, ForwardIterator last, Generator gen);

#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int randomNumber()
{
    return std::rand() % 100;
}

void basic()
{
    // create [0, 0, 0, 0]
    vector<int> v(4);

    vector<int> zeros = {0, 0, 0, 0};
    assert(v == zeros);

    // fill with random numbers by calling RandomNumber repeatedly
    std::generate(v.begin(), v.end(), randomNumber);

    assert(v != zeros);
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
