/*
The ranges library (C++20) is an extension and generalization of the algorithms
and iterator libraries that makes them more powerful by making them
composable and less error-prone.
https://en.cppreference.com/w/cpp/ranges
*/

#include <algorithm>
#include <cassert>
#include <iostream>
#include <ranges>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

void rangeSort()
{
    // ascending
    vector<int> v = {3, 2, 1, 0, 4};
    ranges::sort(v);
    assert(ranges::is_sorted(v));

    // descending
    ranges::sort(v, std::greater<int>());
    vector<int> exp = {4, 3, 2, 1, 0};
    assert(v == exp);
}

void filterAdaptor()
{
    vector<int> input = {1, 2, 3, 4, 5, 6};

    // use a range adaptor to get all even numbers
    // note: always use 'auto' as the output type of adaptors
    // note: the range adaptor ('output') values are only computed on demand
    //       this improves performance and allows creating inf ranges
    auto output = input | views::filter([] (int n) { return n % 2 == 0; });

    // convert to vector
    vector<int> evenNumbers(output.begin(), output.end());
    vector<int> exp = {2, 4, 6};
    assert(evenNumbers == exp);

    // convert to set
    unordered_set<int> setNumbers(output.begin(), output.end());
    assert(setNumbers.size() == 3);
    assert(setNumbers.contains(2));
    assert(setNumbers.contains(4));
    assert(setNumbers.contains(6));
}

void compose()
{
    // get the square of all even numbers in a vector
    // use the '|' operator to compose expressions
    vector<int> input = {1, 2, 3, 4, 5, 6};

    // lambda expressions are also supported
    auto even = [] (int n) { return n % 2 == 0; };
    auto square = [] (int n) { return n * n; };

    auto output = input
        | views::filter(even)
        | views::transform(square);

    // convert result to vector
    vector<int> result(output.begin(), output.end());
    vector<int> exp = { 4, 16, 36 };
    assert(result == exp);
}

void drop()
{
    // views::drop skips (drops) the first N elements
    // analogous to container.begin() + N
    vector<int> input = {1, 2, 3, 4, 5};

    // drop the first 2 elements
    auto output = input | views::drop(2);

    // convert result to vector
    vector<int> result { output.begin(), output.end() };
    vector<int> exp = {3, 4, 5};
    assert(result == exp);
}

void leftTrimAndUppercase()
{
    string s = "  Hello world";

    // drop_while skips spaces and transform converts what's left to uppercase
    auto conv = s | views::drop_while(::isspace) | views::transform(::toupper);

    // C++23 will add ranges::to<type> which makes this step easier
    string result {conv.begin(), conv.end() };
    assert(result == "HELLO WORLD");
    cout << result;
}

void test()
{
    rangeSort();
    filterAdaptor();
    compose();
    drop();
    leftTrimAndUppercase();
}

int main()
{
    test();

    std::cout << std::endl <<  __FILE__ " tests passed!" << std::endl;
    return 0;
}
