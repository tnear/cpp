// A duration object expresses a time span by means of a count and a period.
// https://cplusplus.com/reference/chrono/duration/

#include <algorithm>
#include <cassert>
#include <chrono>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void time()
{
    chrono::seconds sec{1};

    // convert seconds to milliseconds
    chrono::milliseconds mil{sec};

    // 1000ms = 1s
    assert(mil.count() == 1000);
}

void durationFcn()
{
    chrono::seconds sec{1};
    chrono::milliseconds mil{15};

    // 1000ms - 15 ms = 985ms
    chrono::duration result = sec - mil;
    assert(result.count() == 985);
}

void durationCast()
{
    chrono::seconds sec{11};
    chrono::seconds sec2{1};

    // duration_cast
    chrono::milliseconds diff = duration_cast<chrono::milliseconds>(sec - sec2);
    assert(diff.count() == 10 * 1000);

    // constructor cast
    chrono::milliseconds diff2 = chrono::milliseconds{sec - sec2};
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
