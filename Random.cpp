// Random
// 

#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// C++98 style
void randomIntInRange()
{
    // generate a random integer between [0, 11)
    int r = rand() % 11;
    assert(r >= 0 && r <= 10);

    // generate a random number between [3, 8)
    r = rand() % (8-3) + 3;
    assert(r >= 3 && r <= 7);
}

// C++98 style
void randomDoubleBetween0and1()
{
    // generate a random integer using rand() then divide by the maximum possible value
    double d = static_cast<double>(rand()) / static_cast<double>(RAND_MAX);
    assert(d >= 0 && d <= 1);
}

void test()
{
    // use current time as seed
    srand(time(0));

    randomIntInRange();
    randomDoubleBetween0and1();
}

int main()
{
    test();

    std::cout << std::endl <<  __FILE__ " tests passed!" << std::endl;
    return 0;
}
