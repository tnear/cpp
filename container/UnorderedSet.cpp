// Unordered sets are containers that store unique elements in no particular order,
// and which allow for fast retrieval of individual elements based on their value.
// https://cplusplus.com/reference/unordered_set/unordered_set/

#include <algorithm>
#include <cassert>
#include <functional>
#include <iostream>
#include <ranges>
#include <string>
#include <unordered_set>

using namespace std;

auto customHashFcn = [](const pair<int, int> &p)
{
    // use std::hash to create custom hash values
    auto h1 = std::hash<int>{}(p.first);
    auto h2 = std::hash<int>{}(p.second);

    // xor is a simple (non-secure) way to combine two integral values
    return h1 ^ h2;
};

// create a typedef so that this custom set can easily be used as a function argument
using SetWithCustomHasher = unordered_set<pair<int, int>, std::function<size_t(const pair<int, int> &)>>;

// uses typedef as function argument
void customHashFunctionArg(SetWithCustomHasher &set)
{
    set.insert({1, 2});

    assert(set.count({1, 2}) == 1);
    assert(set.count({-1, -1}) == 0);
}

void customHashFunction()
{
    size_t initialNumBuckets = 0; // (unrelated to the hash function, but required for the constructor we need)

    // create a set which uses the custom hash function for hashing pairs
    SetWithCustomHasher set(initialNumBuckets, customHashFcn);

    // pass this set as a function argument (using typedef)
    customHashFunctionArg(set);
}

// C++20
void contains()
{
    unordered_set<int> s = {2, 1, 0, 4};

    assert(s.contains(0));
    assert(s.contains(4));
    assert(!s.contains(3));
}

void intersectionExample()
{
    unordered_set<int> s1 = {1, 2, 3};
    unordered_set<int> s2 = {2, 3, 4};

    vector<int> result;

    // [2, 3] are in both unordered sets
    // note: can also do set_union
    ranges::set_intersection(s1, s2, back_inserter(result));

    vector<int> exp = {2, 3};
    assert(result == exp);
}

void test()
{
    customHashFunction();
    contains();
    intersectionExample();
}

int main()
{
    test();

    std::cout << std::endl <<  __FILE__ " tests passed!" << std::endl;
    return 0;
}
