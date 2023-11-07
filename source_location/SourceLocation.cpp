/*
The std::source_location is a feature introduced in C++20 that provides a way to
capture information about the source code, such as file names, line numbers,
function names, etc., without using macros like __FILE__ and __LINE__.
https://en.cppreference.com/w/cpp/utility/source_location
*/

#include <cassert>
#include <iostream>
#include <string>
#include <source_location> // C++20 header for source_location

using namespace std;

void log(const std::string &message, const std::source_location &location = std::source_location::current())
{
    // location.file_name() returns the name of the current file
    // location.line() returns the line number
    // location.function_name() returns the name of the function
    std::cout << "File: " << location.file_name()
              << ", Line: " << location.line()
              << ", Function: " << location.function_name()
              << " => " << message << '\n';
}

void testSourceLocation()
{
    // output:
    // File: SourceLocation.cpp, Line: 30, Function: void __cdecl testSourceLocation(void) => From testSourceLocation
    log("From testSourceLocation");
}

void test()
{
    testSourceLocation();

    // output:
    // File: SourceLocation.cpp, Line: 39, Function: void __cdecl test(void) => From test
    log("From test");
}

int main()
{
    test();

    std::cout << std::endl <<  __FILE__ " tests passed!" << std::endl;
    return 0;
}
