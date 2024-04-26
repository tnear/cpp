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
        cout << c;
    }
    cout << '\n';
    gMutex.unlock();
}

void _printWithLockGuard(int n, char c)
{
    // lock_guard acquires lock in constructor and releases lock in destructor
    // prefer lock_guard over lock()/unlock()
    std::lock_guard<mutex> lock { gMutex };

    for (int i = 0; i < n; ++i)
    {
        cout << c;
    }
    cout << '\n';
}

void _printWithScopedLock(int n, char c)
{
    // scoped_lock, unlike lock_guard, supports multiple mutexes.
    // scoped_lock will lock them in a way to avoid deadlocks

    std::scoped_lock lock{gMutex, gMutex2};

    for (int i = 0; i < n; ++i)
    {
        cout << c;
    }
    cout << '\n';
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
    cout << "Lock acquired by thread idx " << threadIdx << ", count = " << count << std::endl;

    _recursiveFunction(count - 1, threadIdx); // recursive call

    cout << "Lock released by thread idx " << threadIdx << ", count = " << count << std::endl;
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

void _attemptToPrint(int id)
{
    // attempt to lock the mutex using try_lock
    if (gMutex.try_lock())
    {
        // if lock is successful, proceed
        cout << "Thread " << id << " acquired the lock" << endl;
        // simulate work
        this_thread::sleep_for(chrono::milliseconds(100));
        // release the lock
        gMutex.unlock();
    }
    else
    {
        // could not acquire lock
        cout << "Thread " << id << " could not acquire the lock" << endl;
    }
}

// try_lock acquires the lock if successful and *skips* if unsuccessful.
// this is different from lock() which *waits* until the lock can be acquired
void tryLock()
{
    thread t1 { _attemptToPrint, 1};
    thread t2 { _attemptToPrint, 2};

    t1.join();
    t2.join();
}

void _multipleMutexes1()
{
    // prefer std::lock over this pattern:
    // gMutex.lock();
    // gMutex2.lock();
    // std::lock operates in a way to help prevent deadlocks.
    // the order of that the locks are acquired is *not* defined.
    std::lock(gMutex, gMutex2);
    cout << "Have both mutexes (1)!\n";

    gMutex.unlock();
    gMutex2.unlock();
}

// note: see scoped_lock for a C++17 approach
void _multipleMutexes2()
{
    // note that the argument order is reversed compared to _multipleMutexes1.
    // this still doesn't deadlock.
    std::lock(gMutex, gMutex2);
    cout << "Have both mutexes (2)!\n";

    gMutex.unlock();
    gMutex2.unlock();
}

void lock()
{
    // std::lock() should be used to acquire multiple mutexes.
    // std::lock operates in a way to help prevent deadlocks.
    std::jthread t1{_multipleMutexes1};
    std::jthread t2{_multipleMutexes2};
}

void test()
{
    lockUnlock();
    lockGuard();
    scopedLock();
    recursiveMutex();
    tryLock();
    lock();
}

int main()
{
    test();

    cout << endl <<  __FILE__ " tests passed!" << endl;
    return 0;
}
