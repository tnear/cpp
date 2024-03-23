# Friend

The `friend` keyword is used to allow a function or another class to access private and protected members of a class. It grants a non-member function or another class special access privileges.

## Friend function
A friend function can be a regular non-member function or a member function of another class. It is not a member function of the class to which it is declared friend, but it can access the class's private and protected members.

```cpp
class Box
{
private:
    double width = 0;
public:
    Box(double w) : width(w) {}
    friend void printWidth(const Box& b);
};

void printWidth(const Box& b) {
    // access private member 'width' of Box
    cout << "Width of box: " << b.width << endl;
}
```

## Friend class
When a class is declared as a friend of another class, *all* the member functions of the friend class can access the private and protected members of the other class.

```cpp
class Box {
private:
    double width = 0;
public:
    Box(double w) : width(w) {}
    friend class BoxPrinter;
};

class BoxPrinter {
public:
    static void printWidth(const Box& b) {
        // access private member 'width' of Box
        cout << "Width of box: " << b.width << endl;
    }
};
```

## Operator overloading
Operator overloading functions often need to access the private members of a class to perform their operations. Declaring these functions as `friend` allows them to access all private and protected members of the class, making it easier to manipulate the object's state directly without needing public getters/setters.

```cpp
class Vector2D {
private:
    float x{}, y{};

public:
    // friend function to overload the + operator
    friend Vector2D operator+(const Vector2D& a, const Vector2D& b);
};

// overload the + operator
Vector2D operator+(const Vector2D& a, const Vector2D& b) {
    // access private members directly because this function is a friend of Vector2D
    return Vector2D(a.x + b.x, a.y + b.y);
}
```

## Use-cases
- Testing and debugging. Sometimes it is easier to grant a test special permissions to test a particular behavior which external clients should not have.
- Operator overloading. See above.
