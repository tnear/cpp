# dynamic_cast

`dynamic_cast` is used in C++ for safely converting pointers of a base type into pointers of a derived type at runtime. It checks the validity of the cast and returns nullptr for pointers (or throws bad_cast for references) if the cast is not valid.

## Example
```cpp

class Base {
public:
    virtual void print() { cout << "Base" << endl; }
    virtual ~Base() {}
};

class Derived1 : public Base {
public:
    void print() override { cout << "Derived1" << endl; }
    void specificFunctionDerived1() { cout << "Specific Function for Derived1" << endl; }
};

class Derived2 : public Base {
public:
    void print() override { cout << "Derived2" << endl; }
    void specificFunctionDerived2() { cout << "Specific Function for Derived2" << endl; }
};

int main() {
    unique_ptr<Base> basePtr = make_unique<Derived1>();
    basePtr->print(); // polymorphism, calls Derived1::print()

    // can dynamic cast to convert Base* to Derived1*
    // because basePtr is of type derived 1
    Derived1 *derived1Ptr = dynamic_cast<Derived1*>(basePtr.get());
    assert(derived1Ptr);

    // invalid attempt to dynamic cast to convert Base* to Derived2*
    Derived2* derived2Ptr = dynamic_cast<Derived2*>(basePtr.get());
    assert(!derived2Ptr);
    return 0;
}
```
