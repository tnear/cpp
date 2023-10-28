// Unordered maps are associative containers that store elements formed by the
// combination of a key value and a mapped value, and which allows for fast
// retrieval of individual elements based on their keys.
// https://cplusplus.com/reference/unordered_map/unordered_map/

#include <algorithm>
#include <cassert>
#include <functional>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

using CharIntMap = unordered_map<char, int>;

void constructor()
{
    // initialization list
    const unordered_map<char, int> m = { {'a', 1}, {'b', 2} };
    assert(m.size() == 2);

    // range constructor
    const unordered_map<char, int> m2 = {m.begin(), m.end()};
    assert(m == m2);

    // 'using' typedef
    CharIntMap m3;
    assert(m3.empty());
    m3['a'] = 1;
    assert(m3.size() == 1);
}

// Note: operator[] is always non-const because it will insert if it doesn't exist
void bracket()
{
    unordered_map<char, int> m = {{'a', 1}, {'b', 2}};
    // access existing elements
    assert(m['a'] == 1);
    assert(m['b'] == 2);

    // create new elements using []:
    m['c'] = 3;
    assert(m['c'] == 3);

    // update existing element
    m['a'] = -1;
    assert(m['a'] == -1);

    const unordered_map<char, int> m2 = {{'a', 1}, {'b', 2}};
    // int value = m2['a']; // compile error due to m2 being const
}

// Note: at() is like operator[] but supports const and non-const
// at() will throw out_of_range exception if element does not exist
void at()
{
    // create const map
    const unordered_map<char, int> m = {{'a', 1}, {'b', 2}};

    // access existing elements using at()
    char elem = m.at('a');
    assert(elem == 1);

    // out_of_range exception
    bool hitException = false;
    try
    {
        int unused = m.at('z');
    }
    catch(const std::out_of_range &e)
    {
        hitException = true;
    }

    assert(hitException);
}

void find()
{
    const unordered_map<char, int> m = {{'a', 1}, {'b', 2}};

    // valid element
    auto it = m.find('a');
    assert(it != m.end());
    // use it->first and it->second to get key/value
    assert(it->first == 'a');
    assert(it->second == 1);

    // invalid element
    it = m.find('z');
    assert(it == m.end());
}

// b/c unordered_map doe snot allow duplicates, count() only returns 0 or 1
void count()
{
    const unordered_map<char, int> m = {{'a', 1}, {'b', 2}};

    size_t c = m.count('a');
    assert(c == 1);

    c = m.count('z');
    assert(c == 0);
}

void erase()
{
    unordered_map<char, int> m = {{'a', 1}, {'b', 2}};

    // delete by key
    assert(m.count('a') == 1);
    m.erase('a');
    assert(m.count('a') == 0);

    // delete by iterator
    auto it = m.find('b');
    m.erase(it);
    assert(m.count('b') == 0);

    assert(m.empty());
}

// Sets the number of buckets in the container (bucket_count) to the most appropriate to contain at least n elements.
// https://cplusplus.com/reference/unordered_map/unordered_map/reserve/
void reserve()
{
    unordered_map<char, int> m;

    // reserve capacity=4
    m.reserve(4);
    m['a'] = 1;
    assert(m.size() == 1);
}

// Returns the hash function used by unordered_map
void hash_function()
{
    unordered_map<char, int> m = {{'a', 1}, {'b', 2}};

    auto fn = m.hash_function();
    // explicit call to hash function (shows that different keys produce different values)
    assert(fn('a') != fn('b'));
}

// use std::hash to create a custom hash function for string type
auto customHashFcn = [](const string &s)
{
    return std::hash<string>()(s);
};

// create a typedef so that this custom map can easily be used as a function argument
using MapWithCustomHasher = unordered_map<string, int, std::function<size_t(const string &)>>;

// uses typedef as function argument
void customHashFunctionArg(MapWithCustomHasher &map)
{
    // add two entries of string -> int
    map["abc"] = 1;
    map["xyz"] = 10;

    assert(map.count("abc") == 1 && map.count("xyz") == 1 && map.count("fake") == 0);
    assert(map["abc"] == 1);
    assert(map["xyz"] == 10);
}

void customHashFunction()
{
    // the constructor which accepts a custom hash function also requires # buckets
    // 10 is a decent placeholder
    size_t initialNumBuckets = 10;

    // create a map of string -> int using the custom hash function (plus initial bucket count)
    MapWithCustomHasher map(initialNumBuckets, customHashFcn);

    // pass this map as a function argument (using typedef)
    customHashFunctionArg(map);
}

void iterate()
{
    unordered_map<char, int> m = {{'a', 1}, {'b', 2}, {'c', 4}};
    vector<char> expKeys = {'a', 'b', 'c'};
    vector<int> expValues = {1, 2, 4};

    vector<char> keys;
    vector<int> values;

    // range-for uses pair<key, value>
    for (const std::pair<char, int> &elem : m)
    {
        keys.push_back(elem.first);
        values.push_back(elem.second);
    }

    assert(keys == expKeys);
    assert(values == expValues);

    keys.clear();
    values.clear();

    // C++17 structured binding
    for (const auto &[key, value] : m)
    {
        keys.push_back(key);
        values.push_back(value);
    }

    assert(keys == expKeys);
    assert(values == expValues);
}

// if an element doesn't exist, [] will insert and default construct a value (zero for int)
void bracketOperator()
{
    string s = "hello world";
    unordered_map<char, int> charMap;

    // reference non-existent element 'x'. This will insert and create value of zero
    charMap['x'];
    assert(charMap.size() == 1);
    assert(charMap['x'] == 0);

    // this behavior is useful incrementing values:
    for (char c : s)
    {
        // this increments zero if elem doesn't exist, and increments existing value if it does
        charMap[c]++;
    }

    assert(charMap['l'] == 3);
    assert(charMap['z'] == 0);
}

// C++20
void contains()
{
    unordered_map<char, int> m = {{'a', 1}, {'b', 2}, {'c', 4}};

    assert(m.contains('a'));
    assert(m.contains('b'));
    assert(!m.contains(-1));
}

void test()
{
    constructor();
    bracket();
    at();
    find();
    count();
    erase();
    reserve();
    hash_function();
    customHashFunction();
    iterate();
    bracketOperator();
    contains();
}

int main()
{
    test();

    std::cout << std::endl <<  __FILE__ " tests passed!" << std::endl;
    return 0;
}
