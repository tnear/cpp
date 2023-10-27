/*
The Curiously Recurring Template Pattern (CRTP) is a C++ idiom used to
achieve static (compile-time) polymorphism. The derived class is passed
as a template argument to a base class.

This example uses a Counter class to track how many instances of a type have been created.
*/

#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// Counter tracks the number if instances of a class which have been created
template <typename Derived>
class Counter
{
public:
    static int getCount()
    {
        return _count;
    }

    Counter() {
        ++_count;
    }
    ~Counter() {
        --_count;
    }

private:
    static int _count;
};

// initialize count to zero
template <typename Derived>
int Counter<Derived>::_count = 0;

// these classes inherit from Counter but use their own
// type as the template argument. This creates a unique
// count parameter for each derived class.
class Class1 : public Counter<Class1>
{
};

class Class2 : public Counter<Class2>
{
};

void basic()
{
    // create two instances of Class1 and one instance of Class2
    Class1 obj1, obj2;
    Class2 aObj1;

    assert(Class1::getCount() == 2);
    assert(Class2::getCount() == 1);
}

void test()
{
    basic();
}

int main()
{
    test();

    std::cout << std::endl <<  __FILE__ " tests passed!" << std::endl;
    return 0;
}
