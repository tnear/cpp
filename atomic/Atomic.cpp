/*
std::atomic ensures that operations on a variable are atomic,
which means that they cannot be interrupted by other threads.
This is useful for preventing race conditions without the
need for mutexes in some simple cases.
*/

#include <algorithm>
#include <atomic>
#include <cassert>
#include <iostream>
#include <string>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

void memoryOrder()
{
    /*
    Memory order is used a function argument to specify how different
    threads are synchronized.
    [loosest]
    memory_order_relaxed: provides no guarantees about order
    memory_order_consume
    memory_order_acquire
    memory_order_release
    memory_order_acq_rel
    memory_order_seq_cst [default]: operations are ordered sequentially consistent
                                    (total global ordering)
    [strictest]
    */
}

void fetchAdd()
{
    atomic<int> counter{0};
    constexpr int NUM = 10000;
    vector<jthread> threads;

    auto atomicIncrementFcn = [&]()
    {
        for (int i = 0; i < NUM; ++i)
        {
            // adds 2 to counter atomically using operator++
            // counter++;
            // counter++;

            // note: counter = counter + 2 is *not* atomic: counter += 2;

            // fetch_add allows specifying memory order plus it returns the previous value
            int prevValue = counter.fetch_add(2, memory_order_relaxed);
        }
    };

    for (int i = 0; i < NUM; ++i)
    {
        // create threads, all of which increment the shared variable 'counter'
        threads.push_back(jthread{atomicIncrementFcn});
    }

    // make jthreads go out of scope
    threads.clear();

    // the atomic variable ensured each increment happened atomically
    assert(counter == 2 * NUM * NUM);
}

std::atomic_flag atomicFlag = ATOMIC_FLAG_INIT;
int gSharedData = 0;

void worker(int id)
{
    // spin until flag is cleared (false), then set it to true
    while (atomicFlag.test_and_set()) { }

    // critical section begins
    cout << "Thread " << id << " entering critical section.\n";
    gSharedData++;
    cout << "Thread " << id << " leaving critical section.\n";
    // critical section ends

    // clear flag
    atomicFlag.clear();
}

// atomic flags are booleans which are guaranteed to be lock-free
// atomic_flag supports test_and_set() and clear()
void atomicFlagTest()
{
    vector<thread> threads;
    constexpr int NUM = 4;

    for (int i = 0; i < NUM; ++i)
        threads.push_back(thread{worker, i});

    for (auto &thread : threads)
        thread.join();

    assert(gSharedData == NUM);
}

void test()
{
    memoryOrder();
    fetchAdd();
    atomicFlagTest();
}

int main()
{
    test();

    std::cout << std::endl <<  __FILE__ " tests passed!" << std::endl;
    return 0;
}
