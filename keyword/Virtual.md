# Virtual

The `virtual` keyword in C++ is used to indicate that a method can be overridden in derived classes.

## Polymorphism
Polymorphism allows methods to do different things based on the object that is calling them.

Class setup:
```cpp
class Base {
public:
    virtual void show()
    {
        cout << "Base class show" << endl;
    }
};

class Derived : public Base {
public:
    void show() override
    {
        cout << "Derived class show" << endl;
    }
};
```

Usage:
```cpp
Base* basePtr = new Derived();
basePtr->show(); // calls Derived::show(), not Base::show()

```

## Virtual table
Virtual tables, or vtables, are used by C++ compilers to support dynamic dispatch of function calls, enabling polymorphism. Each class that uses virtual functions has its own vtable. This table is an array of pointers to the virtual functions accessible by the class's objects.

### Structure
Each entry in the vtable points to an instance of a virtual function accessible by the class.

For derived classes, the vtable is constructed based on the base class's vtable but overrides pointers to functions that are overridden in the derived class.

### Usage
When a virtual function is called on an object, the compiler uses the vtable to look up the function's address at runtime. This allows the correct function implementation to be called, even if the object's type is only known at runtime.

Each object of a class with virtual functions contains a hidden pointer (often called a vptr) that points to its class's vtable. When a virtual function call is made, the vptr is used to find the correct function to call.

### Overhead
Virtual tables introduce a runtime cost due to the indirection (following the vptr to the vtable and then to the function).

Each class with virtual functions adds slightly more memory overhead, as it needs to store the vtable and each object needs a vptr.

### vpointer
The `vpointer` is a pointer to that class's corresponding virtual table. For example, Class A's `vpointer` would point to the `vtable` for Class A. The `vtable` contains function pointers to the virtual functions.
