/*
Concepts perform compile-time validation of template arguments and
perform function dispatch based on properties of types.
https://en.cppreference.com/w/cpp/concepts
This example creates an 'Iterable' concept
*/

#include <array>
#include <cassert>
#include <concepts>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// to print elements in a container, you need begin/end forward iterators
// more complex concepts need a 'requires' expression
template <typename T>
concept Iterable = requires(T t)
{
    { begin(t) } -> std::forward_iterator;
    { end(t) }   -> std::forward_iterator;
};

template <Iterable Container>
void printElements(const Container &container)
{
    for (const auto &elem : container)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

void test()
{
    vector<int> v = {1, 2, 3};
    printElements(v);

    string s = "abc";
    printElements(s);

    std::array<float, 3> a = { 1.1, 2.2, 3.3 };
    printElements(a);

    // compile error: concept 'Iterable<int[3]>' evaluated to false
    //int a[] = {4, 5, 6};
    //printElements(a);
}

int main()
{
    test();

    std::cout << std::endl <<  __FILE__ " tests passed!" << std::endl;
    return 0;
}
