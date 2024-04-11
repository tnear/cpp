/*
This uses template specializations to create values for different structs
during compilation. This is an alternative approach to inheritance. The
advantage of type traits is that there is no runtime cost.
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

struct Small
{
    using SupportsSmall = std::true_type;
    static const int SIZE = 1;
};

struct Large
{
    using SupportsSmall = std::false_type;
    static const int SIZE = 3;
};

// Assuming your getSize and getName are implemented somehow like this:
template <typename T>
constexpr int getSize()
{
    static_assert(T::SupportsSmall::value || std::is_same_v<T, Large>, "Unsupported type");
    return T::SIZE;
}

template <typename T>
constexpr string getName()
{
    if constexpr (T::SIZE == 1)
        return "Small";
    else if constexpr (T::SIZE == 3)
        return "Large";
    else
        static_assert(std::is_same_v<T, void>, "Unsupported type");
}

void basic()
{
    // getSize
    static_assert(getSize<Small>() == 1);
    static_assert(getSize<Large>() == 3);

    // SupportsSmall
    static_assert(Small::SupportsSmall::value);
    static_assert(!Large::SupportsSmall::value);

    // getName
    static_assert(getName<Small>() == "Small");
    static_assert(getName<Large>() == "Large");
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
