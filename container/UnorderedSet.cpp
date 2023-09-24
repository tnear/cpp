// Unordered sets are containers that store unique elements in no particular order,
// and which allow for fast retrieval of individual elements based on their value.
// https://cplusplus.com/reference/unordered_set/unordered_set/

#include <cassert>
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

void customHashFunction()
{
    auto customHashFcn = [] (const pair<int, int> &p)
    {
        // use std::hash to create custom hash values
        auto h1 = std::hash<int>{}(p.first);
        auto h2 = std::hash<int>{}(p.second);

        // xor is a simple (non-secure) way to combine two integral values
        return h1 ^ h2;
    };

    size_t initialNumBuckets = 0; // (unrelated to the hash function, but required for the constructor we need)

    // create a set with a custom hash function which works with pairs
    unordered_set<pair<int, int>, decltype(customHashFcn)> set(initialNumBuckets, customHashFcn);

    set.insert({1, 2});

    assert(set.count({1, 2}) == 1);
    assert(set.count({-1, -1}) == 0);
}

void test()
{
    customHashFunction();
}

int main()
{
    test();

    std::cout << std::endl <<  __FILE__ " tests passed!" << std::endl;
    return 0;
}
