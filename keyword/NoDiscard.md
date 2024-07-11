# NoDiscard.md

The [[nodiscard]] attribute (C++17) signals to the compiler to warn if a user of that function discards a return value.

The attribute can be placed on the declaration, implementation, or both.

## Example
```cpp
[[nodiscard]] int multiply(int a, int b)
{
    return a * b;
}

multiply(3, 4); // <-- warning here due to not using return value
```

## Rationale
A string-literal can be used to explain the rationale about why the result should not be discarded.
```cpp
[[nodiscard("Need multiplication result")]]
int multiply(int a, int b)
{
    return a * b;
}
```

## Resources
- https://en.cppreference.com/w/cpp/language/attributes/nodiscard
