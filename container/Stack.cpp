// Stacks are containers which support LIFO (last-in, first-out)
// https://cplusplus.com/reference/stack/stack/

#include <algorithm>
#include <cassert>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

void pushPopTop()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);

    assert(s.top() == 3);

    s.pop();
    assert(s.top() == 2);

    s.pop();
    assert(s.top() == 1);

    s.pop();
    assert(s.empty());
}

void test()
{
    pushPopTop();
}

int main()
{
    test();

    std::cout << "\n" << __FILE__ " tests passed!" << std::endl;
    return 0;
}
