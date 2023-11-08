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
    memory_order_seq_cst: operations are ordered sequentially consistent
    [strictest]
    */
}

void fetchAdd()
{
    atomic<int> counter = 0;
    constexpr int NUM = 10;
    vector<thread> threads;

    auto atomicIncrementFcn = [&]()
    {
        for (int i = 0; i < NUM; ++i)
        {
            // adds 1 to count atomically
            ++counter;

            // note: if you need to specify a memory order
            // or need the previous value returned, use fetch_add
            // counter.fetch_add(1, memory_order_seq_cst);
        }
    };

    for (int i = 0; i < NUM; ++i)
    {
        // create threads, all of which increment the shared variable 'counter'
        threads.push_back(thread{atomicIncrementFcn});
    }

    for (thread &t : threads)
    {
        t.join();
    }

    // the atomic variable ensured each increment happened atomically
    assert(counter == NUM * NUM);
}

void test()
{
    memoryOrder();
    fetchAdd();
}

int main()
{
    test();

    std::cout << std::endl <<  __FILE__ " tests passed!" << std::endl;
    return 0;
}
