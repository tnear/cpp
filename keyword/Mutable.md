# Mutable

The `mutable` keyword in C++ is used to allow a member of an object to be modified even if the object itself is declared as const. This can be useful for variables that are used to cache data or keep track of state that is not visible outside of the class and does not alter the observable behavior of the object.

## Use-cases

### Caching:
`mutable` allows for the caching of computed values for later use without changing the object's state from an external point of view.

### Lazy Evaluation
`mutable` can be used to implement lazy evaluation, where the value of a property is computed only when it is needed.

### Counting Operations
`mutable` is useful for tracking statistics performed on an object that do not affect its logical state, like counting how many times a getter method has been called.

## Example

```cpp
class Shape {
public:
    // a 'const' method which is permitted to change the member variables 'area' and 'areaCalculated'
    double getArea() const {
        if (!areaCalculated) {
            area = width * height; // assume that this is an expensive operation
            areaCalculated = true;
        }
        return area;
    }

private:
    double width{}, height{};
    mutable double area{};  // cached value
    mutable bool areaCalculated{}; // whether the cache is valid
};
```
