// std::invoke
// invoke accepts a callable object and its arguments then returns the result
// C++17

#include <cassert>
#include <functional>
#include <iostream>

using namespace std;

constexpr int doubler(int n)
{
    return 2 * n;
}

struct Doubler
{
    int call(int n)
    {
        return 2 * n;
    }
};

void testFreeFunction()
{
    constexpr int result = std::invoke(doubler, 5);   
    static_assert(result == 10);
}

void testMemberFunction()
{
    Doubler d;
    int result = std::invoke(&Doubler::call, d, 5);
    assert(result == 10);
}

void testLambda()
{
    int result = std::invoke([]() { return doubler(5); });
    assert(result == 10);
}

void test()
{
    testFreeFunction();
    testMemberFunction();
    testLambda();
}

int main()
{
    test();

    std::cout << std::endl <<  __FILE__ " tests passed!" << std::endl;
    return 0;
}
