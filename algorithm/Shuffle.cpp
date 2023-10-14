// Rearranges the elements in the range [first,last) randomly, using g as uniform random number generator.
// https://cplusplus.com/reference/algorithm/shuffle/
// void shuffle(RandomAccessIterator first, RandomAccessIterator last, URNG&& g);

// Note: std::random_shuffle is deprecated in favor of std::shuffle

#include <algorithm>
#include <cassert>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

void testVector()
{
    vector<int> v = {1, 2, 3, 4};

    // random seed (commented out to make test deterministic)
    //unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    unsigned seed = 0;
    std::shuffle(v.begin(), v.end(), std::default_random_engine(seed));

    vector<int> exp = {3, 4, 2, 1};
    assert(v == exp);
}

void test()
{
    testVector();
}

int main()
{
    test();

    std::cout << std::endl <<  __FILE__ " tests passed!" << std::endl;
    return 0;
}
