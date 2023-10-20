// Return smallest element in range
// https://cplusplus.com/reference/algorithm/min_element/
// ForwardIterator min_element(ForwardIterator first, ForwardIterator last);

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

void testValue()
{
    vector<int> values = {2, 1, 3, 4, 5};
    auto it = std::min_element(values.begin(), values.end());

    assert(*it == 1);
    assert(it == values .begin() + 1);
}

struct MyData
{
    int a = 0;
    int b = 0;
};

void testComparator()
{
    auto fcn = [&] (const MyData &left, const MyData &right)
    {
        if (left.a < right.a)
            return true;

        return left.b <= right.b;
    };

    vector<MyData> values = {MyData{2,3}, MyData{2,4}};

    // use custom comparator for this class
    auto it = std::min_element(values.begin(), values.end(), fcn);
    assert(it == values.begin());
}

void test()
{
    testValue();
    testComparator();
}

int main()
{
    test();

    std::cout << std::endl <<  __FILE__ " tests passed!" << std::endl;
    return 0;
}
