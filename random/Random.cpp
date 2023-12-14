// Random number generation

#include <algorithm>
#include <cassert>
#include <iostream>
#include <random>
#include <string>
#include <vector>

using namespace std;

// C++11 style
int randomIntInRange(int low, int high)
{
    // use random_device to seed a Mersenne Twister engine.
    random_device rd;
    mt19937 mt(rd());

    // create a distribution in the range [low, high]
    uniform_int_distribution<int> dist(low, high);

    // generate a random number in the given range
    return dist(mt);
}

// C++98 style
int randomIntInRangeOld(int low, int high)
{
    // generates a random integer between [low, high]
    int r = (rand() % (high + 1 - low)) + low;
    return r;
}

void testRandomIntInRange()
{
    // generate a random integer between [0, 10]
    int r = randomIntInRangeOld(0, 10);
    assert(r >= 0 && r <= 10);

    r = randomIntInRange(0, 10);
    assert(r >= 0 && r <= 10);

    // generate a random number between [3, 7]
    r = randomIntInRangeOld(3, 7);
    assert(r >= 3 && r <= 7);

    r = randomIntInRange(3, 7);
    assert(r >= 3 && r <= 7);
    cout << r;
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

    testRandomIntInRange();
    randomDoubleBetween0and1();
}

int main()
{
    test();

    std::cout << std::endl <<  __FILE__ " tests passed!" << std::endl;
    return 0;
}
