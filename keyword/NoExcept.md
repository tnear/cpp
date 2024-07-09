# NoExcept.md

The noexcept keyword (C++11) specifies whether a function could throw exceptions.

The keyword typically doesn't affect performance. Use it for readability and clarity.

## Example
```cpp
int multiply(int a, int b) noexcept
{
    return a * b;
}
```

## Resources
- https://en.cppreference.com/w/cpp/language/noexcept_spec
