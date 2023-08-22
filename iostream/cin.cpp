// cin - standard input stream
// https://cplusplus.com/doc/tutorial/basic_io/

#include <algorithm>
#include <cassert>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int getAge()
{
    int age = -1;

    cout << "Enter your age: ";
    cin >> age;

    return age;
}

void test()
{
    // backup the original buffer before redirecting cin
    std::streambuf *originalCinBuffer = cin.rdbuf();

    // simulate user age to be 101
    std::istringstream simulatedInput("101\n");
    cin.rdbuf(simulatedInput.rdbuf());

    // call the function that reads from cin
    const int age = getAge();

    // restore original buffer
    cin.rdbuf(originalCinBuffer);

    // verify that age is returned as 101
    assert(age == 101);
}

void readString()
{
    /*
    string name;
    cout << "Enter your name: ";
    cin >> name;

    // output "Hello, {name}"
    cout << "Hello, " << name << '\n';
    */
}

int main()
{
    test();
    readString();

    std::cout << std::endl <<  __FILE__ " tests passed!" << std::endl;
    return 0;
}
