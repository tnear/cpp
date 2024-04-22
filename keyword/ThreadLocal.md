# thread_local

The `thread_local` keyword in C++ indicates that a variable has thread storage duration. This means that each thread has its own instance of the variable. Modifications to the variable in one thread do not affect its value in any other thread. This is useful for variables that are used in multi-threaded applications where each thread needs its own copy of a variable.

## Example
```cpp
void incrementCounter()
{
    static thread_local int counter = 0; // each thread has its own counter
    counter++;
    cout << "Counter value in thread " << this_thread::get_id() << ": " << counter << endl;
}

int main() {
    thread t1(incrementCounter);
    thread t2(incrementCounter);
    thread t3(incrementCounter);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}
```
