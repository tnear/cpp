// Math.cpp

#include <cmath>
#include <cassert>
#include <iostream>
#include <string>

using namespace std;

// C++ does not have a native function for it, so use the recursive definition
int _nchoosek(int n, int k)
{
    if (k == 0)
        return 1;

    int subResult = _nchoosek(n - 1, k - 1);
    return n * subResult / k;
}

void nchoosek()
{
    int n = 52;
    int k = 3;

    int result = _nchoosek(52, 3);
    assert(result == 22100);
}

void test()
{
    nchoosek();
}

int main()
{
    test();

    std::cout << std::endl <<  __FILE__ " tests passed!" << std::endl;
    return 0;
}
