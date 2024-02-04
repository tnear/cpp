/*

*/

#include <algorithm>
#include <cassert>
#include <deque>
#include <execution>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <regex>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

template <typename, typename = void_t<>>
struct has_mapped_type : false_type
{
};

template <typename T>
struct has_mapped_type<T, void_t<typename T::mapped_type>> : true_type
{
};

// print function for set, map, unordered_set, unordered_map
template <typename T>
void print(const T &container)
{
    cout << "{ ";
    for (const auto &element : container)
    {
        // check for map type
        if constexpr (has_mapped_type<T>::value)
            cout << "(" << element.first << ": " << element.second << ") ";
        else
            cout << element << " "; // for sets, directly print the element
    }
    cout << "}\n";
}

// specialization for vector
template <typename T>
void print(const vector<T> &vec)
{
    cout << "[ ";
    for (const auto &elem : vec)
    {
        cout << elem << " ";
    }
    cout << "]\n";
}

// specialization for 2D vectors
template <typename T>
void print(const vector<vector<T>> &vec)
{
    cout << "2D:\n";
    for (int i = 0; i < vec.size(); ++i)
    {
        cout << to_string(i) << ": ";
        print(vec[i]); // call print() specialization for 1D vector
    }
    cout << '\n';
}

void basic()
{
    vector<int> v = {1, 2, 3};
    print(v);

    vector<vector<int>> vv = {{1, 2}, {3, 4}};
    print(vv);

    set<int> s = {1, 2, 3};
    print(s);

    map<int, string> m = {{1, "one"}, {2, "two"}};
    print(m);

    unordered_map<int, string> um = {{1, "one"}, {2, "two"}};
    print(um);

    unordered_set<int> us = {1, 2, 3, 4};
    print(us);
}

void test()
{
    basic();
}

int main()
{
    test();

    cout << endl
         << __FILE__ " tests passed!" << endl;
    return 0;
}
