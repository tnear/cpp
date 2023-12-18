// Regular Expressions <regex>

#include <cassert>
#include <iostream>
#include <regex>
#include <string>

using namespace std;

void regexSearch()
{
    string input = "The year is 2023 and the month is August.";

    // use a Raw string literal so that characters do not need to be escaped
    regex r(R"###(year is (\d{4}) and the month is (\w+).)###");

    smatch match;

    // regex_search returns TRUE when it finds a match
    bool found = regex_search(input, match, r);
    assert(found);

    assert(match.size() == 3);

    // first element of the result is entire matching string
    assert(match[0] == "year is 2023 and the month is August.");

    // second element of the result is the first capture group
    assert(match[1] == "2023");

    // third element is the second capture group
    assert(match[2] == "August");

    // match positions
    assert(match.position(0) == 4); // "year" begins at idx=4
    assert(match.position(1) == 12); // "2023" begins at idx=12
    assert(match.position(2) == 34); // "August" begins at idx=34
}

// regex_match, unlike regex_search, requires the whole string to match the pattern
void regexMatch()
{
    const regex pattern("apple");

    // returns true because entire string matches pattern
    string text = "apple";
    assert(regex_match(text, pattern));

    // returns false because the entire string does not match the pattern
    text = "apple 2";
    assert(!regex_match(text, pattern));
}

void firstOccurrence()
{
    string input = "hey hello world";

    const regex pattern("he\\w+");

    smatch match;

    // regex_search only finds the first match.
    // although 'hello' also matches, it is not returned
    bool found = regex_search(input, match, pattern);
    assert(found);

    assert(match.size() == 1);
    assert(match[0] == "hey");
}

// the return value is the updated string
// note: overloads exist which work differently
void regexReplace()
{
    const string input = "hey world";

    // find leading h-word
    regex pattern("^h\\w+");

    // replace "hey" with "hello"
    string result = regex_replace(input, pattern, "hello");

    assert(result == "hello world");

    // the input string is unchanged
    assert(input == "hey world");
}

void findAllMatches()
{
    const string input = "This is a test";

    // pattern to find words
    regex pattern("\\w+");

    // use sregex_iterator to iterate over all matches
    sregex_iterator next(input.begin(), input.end(), pattern);
    sregex_iterator end;
    vector<string> results;
    while (next != end)
    {
        // get one match at a time
        smatch match = *next;
        results.push_back(match.str());
        ++next;
    }

    assert(results.size() == 4);
    assert(results[0] == "This");
    assert(results[1] == "is");
    assert(results[2] == "a");
    assert(results[3] == "test");
}

void caseInsensitive()
{
    string input = "HELLO WORLD";

    // use regex::icase to match
    const regex pattern("hello", regex::icase);

    smatch match;
    regex_search(input, match, pattern);

    assert(match.size() == 1);
    assert(match[0] == "HELLO");
}

void test()
{
    regexSearch();
    regexMatch();
    firstOccurrence();
    regexReplace();
    findAllMatches();
    caseInsensitive();
}

int main()
{
    test();

    std::cout << std::endl <<  __FILE__ " tests passed!" << std::endl;
    return 0;
}
