// Apply an operation sequentially to elements of two ranges and return result
// https://cplusplus.com/reference/algorithm/transform/
// std::transform(InputIter first1, InputIter last1, OutputIter result, UnaryOp op)

#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

// get first value of each pair within a vector
// ex: convert: (1, 2), (3, 4), (5, 6) => (1, 3, 5)
void pairExample()
{
    vector<std::pair<int, int>> v;
    v.push_back({1, 2});
    v.push_back({3, 4});
    v.push_back({5, 6});

    // always know size for transform, so preallocate
    vector<int> out(v.size());

    auto getFirstElem = [] (const std::pair<int, int> &pr)
    {
        return pr.first;
    };
    
    std::transform(v.begin(), v.end(), out.begin(), getFirstElem);

    vector<int> expV = {1, 3, 5};
    assert(out == expV);
}

// struct with one field
struct MyStruct
{
    int a;
};

// convert [struct.a] into [a]
void structExample()
{
    vector<MyStruct> v;
    v.push_back(MyStruct{1});
    v.push_back(MyStruct{2});
    v.push_back(MyStruct{3});

    vector<int> out(v.size());

    // lambda to get field 'a' of each struct
    auto getField = [] (const MyStruct &elem)
    {
        return elem.a;
    };

    std::transform(v.begin(), v.end(), out.begin(), getField);

    vector<int> expV = {1, 2, 3};
    assert(out == expV);
}

void test()
{
    pairExample();
    structExample();
}

int main()
{
    test();

    std::cout << std::endl <<  __FILE__ " tests passed!" << std::endl;
    return 0;
}
