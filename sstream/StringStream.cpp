/*
stringstream - work with strings as a stream (like cin).
#include <sstream>
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
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

void splitAtSpace()
{
    string str = "Hello from string stream";
    stringstream ss{str};
    string word;

    // use stream '>>' operator to get one word at a time
    vector<string> words;
    while (ss >> word)
    {
        words.push_back(word);
    }

    vector<string> exp = {"Hello", "from", "string", "stream"};
    assert(words == exp);
}

void splitAtComma()
{
    // use getline to split at a non-space character
    string str = "abc,def,123,456";
    stringstream ss{str};
    string word;
    vector<string> words;

    // getline(istream &, string &str, char delim)
    while (getline(ss, word, ','))
    {
        words.push_back(word);
    }

    vector<string> exp = {"abc", "def", "123", "456"};
    assert(words == exp);
}

void test()
{
    splitAtSpace();
    splitAtComma();
}

int main()
{
    test();

    cout << endl
         << __FILE__ " tests passed!" << endl;
    return 0;
}
