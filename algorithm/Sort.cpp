// Sort elements in range
// https://cplusplus.com/reference/algorithm/sort/
// sort(RandomAccessIterator first, RandomAccessIterator last, Compare comp);

#include <algorithm>
#include <cassert>
#include <execution>
#include <iostream>
#include <string>
#include <numeric>
#include <unordered_map>
#include <vector>

using namespace std;

void sortAscending()
{
    // std::sort sorts ascending by default
    vector<int> v = {3, 2, 10, 1};
    std::sort(v.begin(), v.end());

    vector<int> expV = {1, 2, 3, 10};
    assert(v == expV);
}

void sortDescending()
{
    // use std::greater to sort descending
    vector<int> v = {3, 2, 10, 1};
    std::sort(v.begin(), v.end(), std::greater<int>());

    vector<int> exp = {10, 3, 2, 1};
    assert(v == exp);
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

// this function returns the index of where each element
// in the original array would be located in the sorted array
template <typename T>
vector<int> returnIndexes(const vector<T> &input)
{
    vector<int> output(input.size());
    std::iota(output.begin(), output.end(), 0);

    std::sort(output.begin(), output.end(), [&] (const int left, const int right)
    {
        return input[left] < input[right];
    });

    return output;
}

void testReturnIndexes()
{
    vector<int> v = {3, 1, 2, 5, 4};
    vector<int> indexes = returnIndexes(v);

    // the lowest number (1) is at idx=1
    // 2nd lowest (2) is at idx=2
    // 3rd lowest (3) is at idx=0, ...
    vector<int> exp = {1, 2, 0, 4, 3};
    assert(indexes == exp);
}

void parallel()
{
    // use execution::par in <execution> to run an algorithm in parallel
    vector<int> data = {0, 4, 1, 2, 5, 3, 6};
    std::sort(std::execution::par, data.begin(), data.end());
    vector<int> exp = {0, 1, 2, 3, 4, 5, 6};
    assert(data == exp);
}

void test()
{
    sortAscending();
    sortDescending();
    lambda();
    testReturnIndexes();
    parallel();
}

int main()
{
    test();

    std::cout << std::endl <<  __FILE__ " tests passed!" << std::endl;
    return 0;
}
