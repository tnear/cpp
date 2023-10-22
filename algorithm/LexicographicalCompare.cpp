// Lexicographical compare -- less-than comparison
// https://cplusplus.com/reference/algorithm/lexicographical_compare/
// bool lexicographical_compare(Iter2 first1, Iter2 last1, Iter2 first2, InputIterator2 last2);

#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void basic()
{
    // many data types (such as string and vector) already support the '<' operator
    // which makes lexicographical_compare unnecessary. Char arrays need it.
    char a[] = "Apple";
    char b[] = "Banana";
    char c[] = "Cherry";

    bool result = std::lexicographical_compare(a, a + strlen(a), b, b + strlen(b));
    assert(result);

    result = std::lexicographical_compare(c, c + strlen(c), a, a + strlen(a));
    assert(!result);
}

void test()
{
    basic();
}

int main()
{
    test();

    std::cout << std::endl <<  __FILE__ " tests passed!" << std::endl;
    return 0;
}
