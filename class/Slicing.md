# Slicing
Slicing is when an object of a derived class is assigned to an instance of a base class:

```cpp
class A {
   int foo{};
};

class B : public A {
   int bar{};
};

B b;
A a = b; // 'a' has no information about B's bar member variable
```

## Resources
- https://stackoverflow.com/questions/274626/what-is-object-slicing
