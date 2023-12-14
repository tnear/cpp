/*
Coroutines (C++20)
A coroutine is a function that can suspend execution to be resumed later.
Because they can be suspended, all data for coroutines is stored on the
heap instead of the stack.

They have not yet seen widespread adoption, but the <generator> header
in C++23 may help.
*/

#include <coroutine>
#include <iostream>

using namespace std;

// <no good examples yet>

int main()
{
    std::cout << std::endl <<  __FILE__ " tests passed!" << std::endl;
    return 0;
}
