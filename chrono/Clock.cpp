// A duration object expresses a time span by means of a count and a period.
// https://cplusplus.com/reference/chrono/duration/

#include <algorithm>
#include <cassert>
#include <chrono>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using namespace std::chrono;

// high_resolution_clock is the clock with the shortest tick period.
// It may be a synonym for system_clock or steady_clock.
void highResolutionClock()
{
    time_point now = high_resolution_clock::now();
    // allocate 1 million integers
    vector<int> v(1'000'000);
    time_point later = high_resolution_clock::now();

    // time the allocation in microseconds
    microseconds diff = duration_cast<microseconds>(later - now);
    assert(diff.count() > 50 && diff.count() < 5000);
}

void test()
{
    highResolutionClock();
}

int main()
{
    test();

    std::cout << std::endl <<  __FILE__ " tests passed!" << std::endl;
    return 0;
}
