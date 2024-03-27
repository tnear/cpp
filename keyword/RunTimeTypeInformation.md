# Run Time Type Information

Run-Time Type Information (RTTI) allows the type of an object to be determined during program execution. RTTI is useful in polymorphism, where the type of an object pointed to by a base class pointer is not known at compile time.

## dynamic_cast
`dynamic_cast` is used for safe downcasting, converting a base class to a derived class. It checks at runtime to ensure that the cast is valid. If the cast is invalid, it returns nullptr for pointers or throws std::bad_cast for references.

```cpp
class Base {
public:
    virtual void display() {}
};
class Derived : public Base {
    void display() {}
};

Base* basePtr = new Derived();
Derived* derivedPtr = dynamic_cast<Derived*>(basePtr);
if (derivedPtr) {
    // safe to use derivedPtr
}
```

## typeid operator
The `typeid` operator is used to get the type information of an expression at runtime. It returns a reference to a std::type_info object, representing the type. When used with polymorphic types (classes with virtual functions), it can determine the dynamic type of an object.

## Type-aware systems
Systems that need to inspect objects based on their types can use RTTI to implement type-specific logic.
