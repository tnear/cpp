# Class Basics

## Designated initializers
https://google.github.io/styleguide/cppguide.html#Designated_initializers

Designated initializers (C++20) allows initializing an aggregate ("plain old struct") by naming its fields explicitly:

```cpp
struct Point
{
    float x = 0.0;
    float y = 0.0;
    float z = 0.0;
};

Point p =
{
    .x = 1.0,
    .y = 2.0, // in C++20, the order must match
    // z is unspecified so it will inherit 0.0
};
```

Designated initializers existed in C99.

## Slicing
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
