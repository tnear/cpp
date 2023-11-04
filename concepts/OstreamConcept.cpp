/*
Concepts perform compile-time validation of template arguments and
perform function dispatch based on properties of types.
https://en.cppreference.com/w/cpp/concepts
This example creates an 'Iterable' concept
*/

#include <cassert>
#include <concepts>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// to print elements in a container, you need the ostream '<<' operator
template <typename T>
concept Printable = requires(std::ostream &os, const T &msg) {
    { os << msg };
};

template <Printable T>
void printMessage(const T &msg)
{
    cout << msg << endl;
}

void test()
{
    string s = "abc";
    printMessage(s);

    int i = 10;
    printMessage(i);

    // vector does not have '<<', so compilation fails with:
    // the concept 'Printable<std::vector<int>>' evaluated to false
    vector<int> v = {1, 2, 3};
    //printMessage(v);
}

int main()
{
    test();

    std::cout << std::endl <<  __FILE__ " tests passed!" << std::endl;
    return 0;
}
