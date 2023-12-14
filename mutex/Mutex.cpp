/*
A mutex is a lockable object that is designed to signal when critical sections
of code need exclusive access, preventing other threads from executing concurrently
and accessing the same memory locations.
https://cplusplus.com/reference/mutex/mutex/
*/

#include <algorithm>
#include <cassert>
#include <iostream>
#include <mutex>

using namespace std;

std::mutex gMutex; // mutex for critical section
std::mutex gMutex2; // mutex for critical section

void _printWithLockUnlock(int n, char c)
{
    // critical section between lock/unlock
    // not exception safe, see lock_guard for a modern approach
    gMutex.lock();
    for (int i = 0; i < n; ++i)
    {
        std::cout << c;
    }
    std::cout << '\n';
    gMutex.unlock();
}

void _printWithLockGuard(int n, char c)
{
    // lock_guard acquires lock in constructor and releases lock in destructor
    // prefer lock_guard over lock()/unlock()
    std::lock_guard<mutex> lock { gMutex };

    for (int i = 0; i < n; ++i)
    {
        std::cout << c;
    }
    std::cout << '\n';
}

void _printWithScopedLock(int n, char c)
{
    // scoped_lock, unlike lock_guard, supports multiple mutexes
    std::scoped_lock lock{gMutex, gMutex2};

    for (int i = 0; i < n; ++i)
    {
        std::cout << c;
    }
    std::cout << '\n';
}

// note: prefer lock_guard over lock()/unlock()
void lockUnlock()
{
    thread th1(_printWithLockUnlock, 100, '!');
    thread th2(_printWithLockUnlock, 100, '@');
    thread th3(_printWithLockUnlock, 100, '#');

    th1.join();
    th2.join();
    th3.join();
}

// lock_guard is recommended for exactly one mutex
void lockGuard()
{
    thread th1(_printWithLockGuard, 100, '$');
    thread th2(_printWithLockGuard, 100, '%');
    thread th3(_printWithLockGuard, 100, '^');

    th1.join();
    th2.join();
    th3.join();
}

// scoped_lock is recommended for 2+ mutexes
void scopedLock()
{
    thread th1(_printWithScopedLock, 100, '$');
    thread th2(_printWithScopedLock, 100, '%');
    thread th3(_printWithScopedLock, 100, '^');

    th1.join();
    th2.join();
    th3.join();
}

std::recursive_mutex gRecursiveMutex;

void _recursiveFunction(int count, int threadIdx)
{
    if (count <= 0)
        return;

    gRecursiveMutex.lock();
    std::cout << "Lock acquired by thread idx " << threadIdx << ", count = " << count << std::endl;

    _recursiveFunction(count - 1, threadIdx); // recursive call

    std::cout << "Lock released by thread idx " << threadIdx << ", count = " << count << std::endl;
    gRecursiveMutex.unlock();
}

void recursiveMutex()
{
    // a recursive mutex allows the same thread to lock() a mutex repeatedly.
    // note: unlock() must be called the same number of times to release the lock
    thread t0{_recursiveFunction, 4, 0};
    thread t1{_recursiveFunction, 4, 1};

    t0.join();
    t1.join();
}

void test()
{
    lockUnlock();
    lockGuard();
    scopedLock();
    recursiveMutex();
}

int main()
{
    test();

    std::cout << std::endl <<  __FILE__ " tests passed!" << std::endl;
    return 0;
}
