// A container supporting FIFO operations. Elements are pushed into back and popped from front.
// https://cplusplus.com/reference/queue/queue/

#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

void push()
{
    queue<int> q;
    q.push(1);
    q.push(2);

    int value = q.front();
    assert(value == 1);
    q.pop();

    value = q.front();
    assert(value == 2);
}

void clear()
{
    // std::queue lacks a clear function
    // instead, the easiest way is to assign to '{}'
    queue<int> q1;
    q1.push(1);
    q1 = {};
    assert(q1.empty());
}

void test()
{
    push();
    clear();
}

int main()
{
    test();

    std::cout << std::endl <<  __FILE__ " tests passed!" << std::endl;
    return 0;
}
