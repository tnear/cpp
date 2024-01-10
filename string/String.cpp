#include <algorithm>
#include <cassert>
#include <iostream>
#include <ranges>
#include <sstream>
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
string replaceAll(const string &source, const string &from, const string &to)
{
    string ret = source;
    size_t start_pos = 0;
    while ((start_pos = ret.find(from, start_pos)) != string::npos)
    {
        ret.replace(start_pos, from.length(), to);
        start_pos += to.length(); // handles case where 'to' is a substring of 'from'
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
// size_t idx = haystack.find(needle)
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

// returns all indexes of a string
// ex: "a b a c" for "a" returns indexes [0, 4]
vector<size_t> findAll(const string &haystack, const string &needle)
{
    vector<size_t> indexes;

    size_t pos = haystack.find(needle);
    while (pos != string::npos)
    {
        indexes.push_back(pos);
        pos = haystack.find(needle, pos + 1);
    }
    return indexes;
}

void findAll()
{
    string s = "abc def abc xyz";
    string t = "abc";
    vector<size_t> indexes = findAll(s, t);
    assert(indexes.size() == 2);
    assert(indexes[0] == 0);
    assert(indexes[1] == 8);
}

void find_first_of()
{
    // searches for ANY characters which match

    string s = "hello world";

    // none of these chars exist, so -1 is returned
    string toFind = "xyz";
    size_t out = s.find_first_of(toFind);
    assert(out == -1);

    // success example (finds the 'e'):
    out = s.find_first_of("xyze");
    assert(out == 1);
}

// string& erase(size_t pos = 0, size_t len = npos)
void erase()
{
    // position erase
    string s = "hello world";
    // erase "hello " (len = 6)
    int len = 6;
    s.erase(0, len);
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

    // erase only the first 'l'
    s = "hello";
    len = 1;
    s.erase(s.find('l'), len);
    assert(s == "helo");
}

// note: std::to_string cannot customize precision, use stringstream instead
void intToString()
{
    // convert integer to string
    assert(std::to_string(321) == "321");

    // convert double to string
    string result = std::to_string(3.141);
    assert(result == "3.141000");
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
    assert(std::is_sorted(s.begin(), s.end()));

    // gather duplicate characters
    auto it = std::unique(s.begin(), s.end());
    assert(it == s.begin() + 3);

    // erase them
    s.erase(it, s.end());
    assert(s == "abc");
}

// stod: str -> double
// stof: str -> float
void stringToDouble()
{
    string str = " 123.456 "; // stod strips whitespace
    double result = std::stod(str);
    assert(result == 123.456);
}

// C++ lacks a native trim function for strings.
// https://stackoverflow.com/questions/216823/how-to-trim-an-stdstring
string& trim(string &str)
{
    str.erase(str.find_last_not_of(' ') + 1); // suffix spaces
    str.erase(0, str.find_first_not_of(' ')); // prefix spaces
    return str;
}

void trimFunction()
{
    string s = " a b c  ";
    trim(s);
    assert(s == "a b c");
}

void assign()
{
    string s;

    size_t numel = 5;
    char value = ' ';

    // use assign() to create N elements of a particular value
    s.assign(numel, value);
    assert(s == "     ");
}

// string& insert(size_t pos, const string &str)
void insert()
{
    string s = "bcd";

    // insert at beginning of string
    s.insert(0, "a");
    assert(s == "abcd");

    // insert at idx=1
    s.insert(1, "_-");
    assert(s == "a_-bcd");
}

// as of C++20, transform is still the best way without external dependencies
void lowerUpper()
{
    string s = "Hello";

    // lowercase
    std::transform(s.begin(), s.end(), s.begin(), ::tolower);
    assert(s == "hello");

    // uppercase
    std::transform(s.begin(), s.end(), s.begin(), ::toupper);
    assert(s == "HELLO");

    // ranges (C++20)
    s = "Hello";
    auto conv = s | views::transform(::tolower);
    string result { conv.begin(), conv.end() };
    assert(result == "hello");
}

// as of C++20, this is still the best way to split strings
vector<string> split(const string &input, char separator)
{
    vector<string> result;
    stringstream ss(input);
    string token;

    while (getline(ss, token, separator))
    {
        result.push_back(token);
    }

    return result;
}

void split()
{
    string s = "abc;def;ghi";
    char separator = ';';

    vector<string> result = split(s, separator);
    vector<string> exp = {"abc", "def", "ghi"};
    assert(result == exp);
}

string join(const vector<string> &input, char separator)
{
    string result;
    for (int i = 0; i < input.size(); ++i)
    {
        result += input[i];
        result += separator;
    }

    result.pop_back();
    return result;
}

void join()
{
    vector<string> v = {"hello", "world", "test"};
    string result = join(v, ',');
    assert(result == "hello,world,test");

    v = {"hello"};
    result = join(v, ',');
    assert(result == "hello");
}

// C++20
void startsWith()
{
    string s = "my test string";
    assert(s.starts_with("my test"));
    assert(!s.starts_with("string"));
}

// C++20
void endsWith()
{
    string s = "my test string";
    assert(s.ends_with("string"));
    assert(!s.ends_with("my test"));
}

void test()
{
    replace();
    replaceAllChar();
    replaceAllString();
    substring();
    find();
    findAll();
    find_first_of();
    erase();
    intToString();
    stringToInt();
    append();
    removeDuplicates();
    stringToDouble();
    trimFunction();
    assign();
    insert();
    lowerUpper();
    split();
    join();
    startsWith();
    endsWith();
}

int main()
{
    test();

    std::cout << std::endl <<  __FILE__ " tests passed!" << std::endl;
    return 0;
}
