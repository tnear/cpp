// cout - standard output stream
// https://cplusplus.com/doc/tutorial/basic_io/

#include <algorithm>
#include <cassert>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void basic()
{
    int n = 10;
    double x = 3.14;

    // outputs, "hello 10 3.14"
    cout << "hello " << n << " " << x << '\n';
}

void precision()
{
    double pi = 3.14159265358979;

    // set 4 digits of precision
    cout.precision(4);

    // outputs, "3.142" (twice)
    cout << pi << '\n';
    cout << pi << '\n';

    // using setprecision (outputs 3.1416)
    cout << setprecision(5) << pi << '\n';
}

void test()
{
    basic();
    precision();
}

int main()
{
    test();

    std::cout << std::endl <<  __FILE__ " tests passed!" << std::endl;
    return 0;
}
