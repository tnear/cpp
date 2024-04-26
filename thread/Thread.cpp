/*
(C++11) Threads of execution in a shared address space
https://cplusplus.com/reference/thread/thread/
*/

#include <algorithm>
#include <atomic>
#include <cassert>
#include <chrono>
#include <iostream>
#include <string>
#include <thread>
#include <vector>

using namespace std;

void _doWork(int milliseconds)
{
    cout << "Sleeping for " << milliseconds << " milliseconds...\n";
    this_thread::sleep_for(chrono::milliseconds(milliseconds));
}

void sleepFor()
{
    // sleep (pause) this thread for 5 milliseconds
    this_thread::sleep_for(chrono::milliseconds(5));
}

void joinable()
{
    // joinable() returns false if a thread is default constructed
    // or if join has already been called
    std::thread th;
    assert(!th.joinable());

    // a thread with a function pointer is joinable
    std::thread th2 { _doWork, 4 };
    assert(th2.joinable());
    th2.join();
    // the thread is no longer joinable after calling join()
    assert(!th2.joinable());

}

void hardwareConcurrency()
{
    cout << "The approximate # of processors on this machine: " << thread::hardware_concurrency() << endl;
}

void _increment(int &n)
{
    ++n;
}

void arguments()
{
    // _increment accepts int&. This thread increments that value.
    // reference parameters are used to return values.
    // note: std::atomic is a better way to increment and future/promise
    //       are better for returning values.
    int n = 0;
    std::thread t1 { _increment, std::ref(n) };
    t1.join(); // wait for thread to execute

    assert(n == 1);
}

void _print(const vector<string> &str, size_t idx)
{
    cout << str[idx] << endl;
}

void multipleThreads()
{
    vector<string> s = {"hello", "world", "testing", "123"};

    // hold all threads in a vector
    vector<thread> threads;
    for (size_t idx = 0; idx < s.size(); ++idx)
    {
        // the order that _print() is called is not guaranteed
        threads.push_back(thread{_print, s, idx});
    }

    // wait for all threads to complete
    for (thread &t : threads)
    {
        t.join();
    }
}

atomic<bool> gReady = false;

void _count(int threadIdx)
{
    // yield offers the implementation the opportunity to reschedule
    while (!gReady)
    {
        // not yet ready, yield to other threads
        this_thread::yield();
    }

    // count to 1M
    for (volatile int i = 0; i < 1'000'000; ++i)
    {
    }

    cout << "Thread " << threadIdx << " finished\n";
}

void yield()
{
    constexpr int num = 4;
    thread threads[num];

    for (int i = 0; i < num; ++i)
    {
        threads[i] = thread{_count, i};
    }

    // set ready
    gReady = true;

    for (thread &t : threads)
    {
        t.join();
    }
}

void returnValue()
{
    
}

void test()
{
    sleepFor();
    joinable();
    hardwareConcurrency();
    arguments();
    multipleThreads();
    yield();
    returnValue();
}

int main()
{
    test();

    std::cout << std::endl <<  __FILE__ " tests passed!" << std::endl;
    return 0;
}
