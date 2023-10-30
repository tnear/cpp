/*
Deque is a double-ended queue which supports pushing and popping from both ends.
It is less efficient than a vector for push_back and pop_back.
https://cplusplus.com/reference/deque/deque/
*/

#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

void front()
{
    deque<int> d;

    // create [3, 2, 1]
    d.push_front(1);
    d.push_front(2);
    d.push_front(3);

    assert(d.front() == 3);
    assert(d[1] == 2);
    assert(d[2] == 1);

    d.pop_front();
    assert(d[0] == 2);

    d.clear();
    assert(d.empty());
}

void test()
{
    front();
}

int main()
{
    test();

    std::cout << "\n" << __FILE__ " tests passed!" << std::endl;
    return 0;
}
