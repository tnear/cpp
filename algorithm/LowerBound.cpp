// Return iterator to lower bound
// O(lg n) algorithm
// https://cplusplus.com/reference/algorithm/lower_bound/
// lower_bound(ForwardIterator first, ForwardIterator last, const T& val);

#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// lower_bound returns iterator to 1st elem NOT considered to go before VAL
// upper_bound returns iterator to 1st elem which goes after VAL
void basic()
{
    // std::lower_bound requires inputs to be sorted
    vector<int> v = {1, 2, 3, 4, 5, 7, 8};
    assert(std::is_sorted(v.begin(), v.end()));

    // returns is an iterator to first element in logarithmic time which does not compare < val
    auto it = std::lower_bound(v.begin(), v.end(), 3);

    // returns 3 because 3 is first element not less than 3
    assert(*it == 3);

    // search non-existent element (6). Returns 7.
    it = std::lower_bound(v.begin(), v.end(), 6);
    assert(*it == 7);

    // search smaller than min (-1), returns smallest element
    it = std::lower_bound(v.begin(), v.end(), -1);
    assert(*it == 1);
}

// example of using lower_bound to do binary search
void binarySearch()
{
    // create a vector with a missing element (2)
    vector<int> v = {1, 3, 4, 5, 6};

    // 2 is not in array, so lower_bound returns 1st elem which is not < val (3 in this case)
    auto it = std::lower_bound(v.begin(), v.end(), 2);
    bool found = *it == 2;
    assert(!found);
    assert(*it == 3);
}

// lower_bound returns iterator to 1st elem NOT considered to go before VAL
// for [3, 4, 5, 7] and searching for 6,
// lower_bound returns 7 (because 7 does not go before 6)
// this is why you must check if return equals the target before returning index
int _getIndex(const vector<int> &v, int value)
{
    auto it = ranges::lower_bound(v, value);
    if (it != v.end() && *it == value)
        return distance(v.begin(), it); // found!

    return -1; // did not find
}

void getIndex()
{
    vector<int> v = {3, 4, 5, 7};

    assert(_getIndex(v, 5) == 2);
    assert(_getIndex(v, 6) == -1);
    assert(_getIndex(v, 100) == -1);
}

struct S
{
    int field{};
};

void customComparator()
{
    S s1{10};
    S s2{20};
    S s3{30};
    S s4{40};
    vector<S> data = {s1, s2, s3, s4};

    // use custom comparator to get the 'a' field of a struct
    auto comp = [] (S &s, int value)
    {
        return s.field < value;
    };

    // this returns 30 b/c 30 is the first element which does not come before 25
    auto it = std::lower_bound(data.begin(), data.end(), 25, comp);
    assert((*it).field == 30);

    // ranges not supported?
    //auto it2 = ranges::lower_bound(data, 25, comp);
}

void test()
{
    basic();
    binarySearch();
    getIndex();
    customComparator();
}

int main()
{
    test();

    std::cout << std::endl <<  __FILE__ " tests passed!" << std::endl;
    return 0;
}
