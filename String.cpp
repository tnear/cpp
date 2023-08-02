#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Note: replace() replaces ONE occurrence, not all.
// https://cplusplus.com/reference/string/string/replace/
void replace()
{
    // replace from [0, 2) ("my") with hello
    string s = "my world";
    s.replace(s.begin(), s.begin() + 2, "hello");
    assert(s == "hello world");

    // longer replacement strings are supported
    s = "hello world";
    s.replace(s.begin(), s.end(), "longer string example");
    assert(s == "longer string example");
}

// std::replace() in <algorithm> replaces one char with another (but not one string with another)
void replaceAllChar()
{
    string s = "hello world";

    // replace all 'l' with 'y'
    std::replace(s.begin(), s.end(), 'l', 'y');
    assert(s == "heyyo woryd");
}

// https://stackoverflow.com/questions/2896600/how-to-replace-all-occurrences-of-a-character-in-string
string replaceAll(const string &str, const string &from, const string &to)
{
    string ret = str;
    size_t start_pos = 0;
    while ((start_pos = ret.find(from, start_pos)) != string::npos)
    {
        ret.replace(start_pos, from.length(), to);
        start_pos += to.length(); // Handles case where 'to' is a substring of 'from'
    }
    return ret;
}

void replaceAllString()
{
    string s = "hello to all";
    string ret = replaceAll(s, " ", "%20");
    assert(ret == "hello%20to%20all");
}

void substring()
{
    string s = "hello world";

    // get elements [2, 3, 4] of source string
    size_t offset = 2;
    size_t count = 3;
    string sub = s.substr(offset, count);
    assert(sub == "llo");

    // get remainder of string by leaving off count parameter
    sub = s.substr(6);
    assert(sub == "world");
}

// find substring within a string
void find()
{
    string s = "hello world";

    {
        // find "wor" starting from beginning of string
        string toFind = "wor";
        size_t out = s.find(toFind);
        // "wor" begins at index=6
        assert(out == 6);
    }

    // not found
    {
        size_t out = s.find("fake", 0);
        assert(out == string::npos);
        assert(out == -1);
    }
}

void find_first_of()
{
    // searches for ANY characters which match

    string s = "hello world";

    // none of these chars exist, so -1 is returned
    string toFind = "xyz";
    size_t out = s.find_first_of(toFind);
    assert(out == -1);

    // success example:
    out = s.find_first_of("xyze");
    assert(out == 1);
}

// string& erase(size_t pos = 0, size_t len = npos)
void erase()
{
    // position erase
    string s = "hello world";
    // erase "hello "
    s.erase(0, 6);
    assert(s == "world");

    // iterator erase
    s = "hello world";
    // remove 'll'
    s.erase(s.begin() + 2, s.begin() + 5);
    assert(s == "he world");

    // remove all letter 'l' using std::remove + erase()
    s = "hello world";
    s.erase(std::remove(s.begin(), s.end(), 'l'), s.end());
    assert(s == "heo word");
}

void intToString()
{
    int x = 321;
    assert(std::to_string(321) == "321");
}

void stringToInt()
{
    string s = "1234";
    int result = stoi(s);
    assert(result == 1234);
}

void append()
{
    string s = "hello";
    // append string
    s.append(" world");
    assert(s == "hello world");

    // append one char
    s.append("!");
    assert(s == "hello world!");

    // builder (append returns reference to itself)
    s = string{};
    s.append("a").append("b").append("c");
    assert(s == "abc");
}

void removeDuplicates()
{
    // see Unique.cpp for more info
    string s = "aabcc";
    auto it = std::unique(s.begin(), s.end());
    assert(it == s.begin() + 3);
    s.erase(it, s.end());
    assert(s == "abc");
}

void test()
{
    replace();
    replaceAllChar();
    replaceAllString();
    substring();
    find();
    find_first_of();
    erase();
    intToString();
    stringToInt();
    append();
    removeDuplicates();
}

int main()
{
    test();

    std::cout << std::endl <<  __FILE__ " tests passed!" << std::endl;
    return 0;
}
