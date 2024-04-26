/*
A condition variable is an object that is able to block the
calling thread until notified to resume.
https://cplusplus.com/reference/condition_variable/condition_variable/
*/

#include <cassert>
#include <condition_variable>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

mutex gMutex;
condition_variable gConditionVar;
queue<int> gDataQueue;
bool gDone = false; // indicates when producers have finished producing

void producer(int id, int count)
{
    for (int i = 0; i < count; ++i)
    {
        {
            scoped_lock guard{gMutex}; // C++17 scoped_lock. the older lock_guard also works.
            cout << "Producer " << id << " produced " << i << endl;

            gDataQueue.push(i);
        }

        // simulate work
        this_thread::sleep_for(chrono::milliseconds(140));

        // notify one consumer waiting on this condition variable
        // note: it is safe to call notify_one() after releasing the lock
        gConditionVar.notify_one();
    }
}

// note: consumers cannot consume data until something is produced by the producer.
// if, for whatever reason, the consumer() thread starts first, it will have nothing
// to consume. therefore, it needs a mechanism to wait() until data exists.
void consumer(int id)
{
    while (true)
    {
        // waiting for a condition_variable is a 2-step process:
        // 1. acquire the lock using unique_lock (not lock_guard)
        unique_lock<mutex> guard{gMutex};
        // 2. wait for condition variable. wait() causes the current thread
        // to block until the condition variable is notified or a spurious wakeup occurs.
        // a predicate should return true when the thread is able to continue, and return
        // false when the thread should continue waiting
        gConditionVar.wait(guard, [] { return gDataQueue.size() || gDone; });

        while (!gDataQueue.empty())
        {
            int value = gDataQueue.front();
            gDataQueue.pop();
            cout << "Consumer " << id << " consumed " << value << endl;
        }

        if (gDone)
        {
            break;
        }
    }
}

void test()
{
    int numProducers = 4;
    int numConsumers = 4;
    int itemsPerProducer = 5;

    vector<jthread> producers;
    vector<jthread> consumers;

    for (int i = 0; i < numProducers; ++i)
        producers.push_back(jthread{producer, i, itemsPerProducer});

    for (int i = 0; i < numConsumers; ++i)
        consumers.push_back(jthread{consumer, i});

    {
        // ensure all producers are done
        scoped_lock guard(gMutex);
        gDone = true;
    }

    gConditionVar.notify_all(); // notify all consumers
}

int main()
{
    test();

    cout << endl
         << __FILE__ " tests passed!" << endl;
    return 0;
}
