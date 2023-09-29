// string_view family of template specializations provides an efficient way to pass a
// read-only, exception-safe, non-owning handle to the character data of any string-like objects
// C++17

#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <string_view>

using namespace std;

// a string_view is a non-owning reference to a string. Internally, it is a pointer + length.
// string_view avoids unnecessary copies by providing a read-only view of a string

void init()
{
    // string_view can be initialized from different string types

    // string_view from C-style string
    string_view sv = "hello";

    // string_view from std::string
    string s = "hello";
    string_view sv2 = s;

    // string_view from string_view
    string_view sv3 = sv;
    assert(sv3 == "hello");

    // string from string_view (string becomes owner and makes deep copy)
    string s2 { sv };
    assert(s2 == "hello");
}

void stringView()
{
    string s = "hello"; // incurs a copy from C-style string to std::string

    // string_view avoids unnecessary copies
    string_view sv = "hello";
    // sv[0] = 'a'; // modifying a string_view is a compilation error
    assert(sv == "hello");
}

// string_view allows creating substrings without unnecessary copies using its substr() method
void stringViewSubstring()
{
    string_view sv = "hello, world";

    // get substring without making any copies
    size_t start = 7;
    size_t len = 3;
    string_view sub = sv.substr(start, len);
    assert(sub == "wor");
}

void constexprFcn()
{
    // string_view has stronger constexpr support than std::string
    constexpr string_view sv = "hello world";
    static_assert(sv == "hello world");
}

void test()
{
    init();
    stringView();
    stringViewSubstring();
    constexprFcn();
}

int main()
{
    test();

    std::cout << std::endl <<  __FILE__ " tests passed!" << std::endl;
    return 0;
}
