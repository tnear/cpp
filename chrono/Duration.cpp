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

void time()
{
    seconds sec{1};

    // convert seconds to milliseconds
    milliseconds mil{sec};

    // 1000ms = 1s
    assert(mil.count() == 1000);
}

void durationFcn()
{
    seconds sec{1};
    milliseconds mil{15};

    // 1000ms - 15 ms = 985ms
    duration result = sec - mil;
    assert(result.count() == 985);
}

void durationCast()
{
    seconds sec{11};
    seconds sec2{1};

    // duration_cast
    milliseconds diff = duration_cast<milliseconds>(sec - sec2);
    assert(diff.count() == 10 * 1000);

    // constructor cast
    milliseconds diff2 = milliseconds{sec - sec2};
    assert(diff2.count() == 10 * 1000);
}

void test()
{
    time();
    durationFcn();
    durationCast();
}

int main()
{
    test();

    std::cout << std::endl <<  __FILE__ " tests passed!" << std::endl;
    return 0;
}
