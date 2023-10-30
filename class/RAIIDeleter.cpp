//

#include <algorithm>
#include <cassert>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool g_called = false;

class RAIIDeleter
{
public:
    RAIIDeleter(std::function<void(void)> onCleanup)
        : _onCleanup(onCleanup)
    {}

    ~RAIIDeleter()
    {
        _onCleanup(); // use destructor to ensure onCleanup is always called
    }

private:
    std::function<void(void)> _onCleanup;
};

void testDeleter()
{
    vector<int> vec = {1, 2, 3};
    auto onCleanup = [&]()
    {
        assert(vec.size() == 3);
        g_called = true;
    };

    RAIIDeleter d{onCleanup};
    // do something which may return early or throw exceptions
}

void test()
{
    assert(!g_called);
    testDeleter();
    assert(g_called);
}

int main()
{
    test();

    std::cout << std::endl <<  __FILE__ " tests passed!" << std::endl;
    return 0;
}
