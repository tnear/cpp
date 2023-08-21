// std::remove_if does NOT alter elements in a container. It only returns an iterator
// to the new end of the range. Calling std::remove_if is a 2-step process.
// std::remove_if uses predicates, unlike std::remove
// https://cplusplus.com/reference/algorithm/remove_if/
// remove_if(ForwardIterator first, ForwardIterator last, UnaryPredicate pred);

#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void removeVowels()
{
    // remove all vowels
    // note: can only remove one letter using 'std::remove', not an entire string
    string s = "hello world";

    // returns TRUE when a value should be removed
    auto fn = [] (const char ch)
    {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    };

    // find new end of string location
    auto it = std::remove_if(s.begin(), s.end(), fn);

    // use 'erase' to modify the string
    s.erase(it, s.end());

    // verify vowels are removed
    assert(s == "hll wrld");
}

void test()
{
    removeVowels();
}

int main()
{
    test();

    std::cout << std::endl <<  __FILE__ " tests passed!" << std::endl;
    return 0;
}
