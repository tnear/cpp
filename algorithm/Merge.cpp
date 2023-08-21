// Combines the elements in the sorted ranges into new range
// https://cplusplus.com/reference/algorithm/merge/
// merge(InputIter1 first1, InputIter last1, InputIter2 first2, InputIter2 last2, OutputIter result, Compare comp);

#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void basic()
{
    vector<int> v = {1, 2, 3, 10};
    vector<int> w = {3, 4, 5};

    assert(std::is_sorted(v.begin(), v.end()));
    assert(std::is_sorted(w.begin(), w.end()));

    // you always know the size for merge, so preallocating is faster than back_inserter
    vector<int> out(v.size() + w.size());
    
    // merge v and w into out
    std::merge(v.begin(), v.end(), w.begin(), w.end(), out.begin());

    // verify the two ranges have been merged
    vector<int> expV = {1, 2, 3, 3, 4, 5, 10};
    assert(out == expV);
}

void lambda()
{
    // REVERSE order using comparator
    vector<int> v = {10, 3, 2, 1};
    vector<int> w = {5, 4, 3};

    // lambda returns TRUE when the lhs should go before rhs
    // ex: elem1 > elem2 says higher elements go on left, which is descending sort
    auto fcn = [](const auto &elem1, const auto &elem2)
    {
        return elem1 > elem2;
    };

    vector<int> out(v.size() + w.size());

    // merge v and w into out
    std::merge(v.begin(), v.end(), w.begin(), w.end(), out.begin(), fcn);

    // verify reverse order
    vector<int> expV = {10, 5, 4, 3, 3, 2, 1};
    assert(out == expV);
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
