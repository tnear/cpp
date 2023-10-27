/*
The Curiously Recurring Template Pattern (CRTP) is a C++ idiom used to
achieve static (compile-time) polymorphism. The derived class is passed
as a template argument to a base class.

This example uses chaining where the base class returns the derived type.
*/

#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

template <typename Derived>
class Animal
{
public:
    Derived &setName(const string &n)
    {
        _name = n;
        return static_cast<Derived &>(*this);
    }

    Derived &setAge(const int age)
    {
        _age = age;
        return static_cast<Derived &>(*this);
    }

    // The base Animal class does not provide a describeImpl() function.
    // This forces derived classes to provide their own describeImpl().
    void describe() const
    {
        static_cast<const Derived *>(this)->describeImpl();
    }

protected:
    string _name;
    int _age = 0;
};

class Dog : public Animal<Dog>
{
public:
    void describeImpl() const
    {
        cout << "Dog named " << _name << " and age " << _age << endl;
    }
};

void basic()
{
    Dog d;
    d.setName("Max").setAge(5);
    d.describe();
}

void test()
{
    basic();
}

int main()
{
    test();

    std::cout << std::endl
              << __FILE__ " tests passed!" << std::endl;
    return 0;
}
