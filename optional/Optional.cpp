// Optional
// https://en.cppreference.com/w/cpp/utility/optional

#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <optional>
#include <vector>

using namespace std;

std::optional<string> getOptional(bool b)
{
    if (b)
        return string{"hello"};
    
    return std::nullopt; // or `return {};`
}

// returns true when argument option is not set
bool isOptionalArgument(std::optional<int> opt)
{
    // these all work:
    // (!opt)
    // (!opt.has_value())
    // (opt = std::nullopt)
    if (!opt)
        return true;

    return false;
}

void testGetOptional()
{
    optional<string> result = getOptional(true);
    assert(*result == "hello");

    result = getOptional(false);
    assert(result == std::nullopt);
    assert(!result);
}

void testOptionalArgument()
{
    std::optional<int> arg = 5;
    assert(!isOptionalArgument(arg));

    arg = std::nullopt;
    assert(isOptionalArgument(arg));
}

void test()
{
    testGetOptional();
    testOptionalArgument();
}

int main()
{
    test();

    std::cout << std::endl <<  __FILE__ " tests passed!" << std::endl;
    return 0;
}
