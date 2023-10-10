// Namespace

#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// C++17 nested namespace
namespace a::b::c
{
    void basic()
    {
        assert(true);
    }
}

void test()
{
    a::b::c::basic();
}

int main()
{
    test();

    std::cout << std::endl <<  __FILE__ " tests passed!" << std::endl;
    return 0;
}
