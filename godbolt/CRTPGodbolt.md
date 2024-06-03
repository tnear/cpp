# CRTP Goldbolt

See also [Virtual Godbolt](VirtualGodbolt.md).

*https://godbolt.org/z/ezrYYPbEP*

## Example

```cpp

// Base class template
template <typename Derived>
class OneCRTP {
public:
    int getNumber() {
        return static_cast<Derived*>(this)->getNumberImpl();
    }
};

// Derived class using CRTP
class One : public OneCRTP<One> {
public:
    int getNumberImpl() {
        return 1;
    }
};

// Another derived class using CRTP
class Two : public OneCRTP<Two> {
public:
    int getNumberImpl() {
        return 2;
    }
};

// Function that uses CRTP without vtable
int noVirtualTable(bool isOne) {
    if (isOne) {
        One obj;
        return obj.getNumber();
    } else {
        Two obj;
        return obj.getNumber();
    }
}

// Function that simulates virtual function usage with CRTP
int vtable(bool isOne) {
    if (isOne) {
        One obj;
        return obj.getNumber();
    } else {
        Two obj;
        return obj.getNumber();
    }
}
```


```
noVirtualTable(bool):                    # @noVirtualTable(bool)
        mov     eax, 2
        sub     eax, edi
        ret
vtable(bool):                             # @vtable(bool)
        mov     eax, 2
        sub     eax, edi
        ret
```
