/*
Arrays are fixed-size sequence containers: they hold a specific number of elements ordered in a strict linear sequence.
https://cplusplus.com/reference/array/array/
*/

#include <cassert>
#include <iostream>
#include <array>

using namespace std;

void constructor()
{
    // explicit type and size
    std::array<int, 3> arr = {1, 2, 3};
    assert(arr.size() == 3);

    // can drop the type and size and let the compiler deduce.
    // arr2 is std::array<int, 3>
    std::array arr2 = {2, 3, 4};
    assert(arr2.size() == 3);
    assert(arr2 != arr);
}

void test()
{
    constructor();
}

int main()
{
    test();

    cout << "\n" << __FILE__ " tests passed!" << endl;
    return 0;
}
