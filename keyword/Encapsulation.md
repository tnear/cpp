# Encapsulation

Encapsulation restricts direct access to some of an object's components, which is a way of preventing accidental modification of data. Encapsulation ensures that an object's internal state cannot be accessed directly. Instead, interactions are performed through its public methods, providing a controlled interface. This leads to increased security and data integrity.

## Example
```cpp
#include <iostream>
using namespace std;

class BankAccount {
private:
    // private attributes
    double balance{};

public:
    BankAccount(double initialBalance) : balance(initialBalance) {}

    // public method to deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }

    // public method to withdraw money
    bool withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            return true;
        }
        return false;
    }

    // public method to check the balance
    double getBalance() const {
        return balance;
    }
};
```
