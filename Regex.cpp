// Regular Expressions <regex>
// 

#include <cassert>
#include <iostream>
#include <regex>
#include <string>

using namespace std;

// regex_search does NOT require the whole string to match the pattern
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
}

// regex_match requires the whole string to match the pattern
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

void test()
{
    regexSearch();
    regexMatch();
}

int main()
{
    test();

    std::cout << std::endl <<  __FILE__ " tests passed!" << std::endl;
    return 0;
}
