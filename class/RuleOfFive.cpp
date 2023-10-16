// The Rule of Five states that if a class ever needs any one of the following, then it should implement all 5:
// (1) copy constructor, (2) copy assignment, (3) destructor, (4) move constructor, (5) move assignment
// The rationale is that managing dynamic resources requires all five for a class to function correctly.

#include <iostream>
#include <cassert>

using namespace std;

class RuleOfFive
{
public:
    // default constructor
    RuleOfFive(int value = 0)
        : _number(new int(value))
    {
        cout << "Default constructor" << endl;
    }

    // destructor
    ~RuleOfFive()
    {
        cout << "Destructor" << endl;
        delete _number;
    }

    // copy constructor
    RuleOfFive(const RuleOfFive &other)
        : _number(new int(*(other._number)))
    {
        cout << "Copy constructor" << endl;
    }

    // copy assignment operator
    RuleOfFive &operator=(const RuleOfFive &other)
    {
        cout << "Copy assignment operator" << endl;

        // protect against invalid self-assignment
        if (this != &other)
        {
            // deallocate old memory
            delete _number;

            // allocate new memory and copy the elements
            _number = new int(*(other._number));
        }
        return *this;
    }

    // move constructor
    RuleOfFive(RuleOfFive &&other) noexcept
        : _number(other._number)
    {
        cout << "Move constructor" << endl;
        other._number = nullptr;
    }

    // move assignment operator
    RuleOfFive &operator=(RuleOfFive &&other) noexcept
    {
        cout << "Move assignment operator" << endl;

        // protect against invalid self-assignment
        if (this != &other)
        {
            // deallocate old memory
            delete _number;

            // transfer ownership of other.number to this object
            _number = other._number;

            // nullify the pointer in the source object
            other._number = nullptr;
        }
        return *this;
    }

    int *getValue() const
    {
        return _number;
    }

private:
    int *_number = nullptr;
};

void test()
{
    // default constructor
    RuleOfFive a(10);
    assert(*a.getValue() == 10);

    // copy constructor
    RuleOfFive b(a);
    assert(*b.getValue() == 10);

    // default constructor
    RuleOfFive c;
    // copy assignment operator
    c = a;
    assert(*c.getValue() == 10);

    // move constructor
    RuleOfFive d(std::move(a));
    assert(*d.getValue() == 10);
    // a has been moved from, so it no longer has a value:
    assert(!a.getValue());

    // default constructor
    RuleOfFive e;
    // move assignment operator
    e = std::move(d);  
    assert(*e.getValue() == 10);
    // d has been moved from, so it no longer has a value:
    assert(!d.getValue());
}

int main()
{
    test();

    std::cout << std::endl
              << __FILE__ " tests passed!" << std::endl;
    return 0;
}
