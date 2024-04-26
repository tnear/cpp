/*
https://en.cppreference.com/w/cpp/thread/latch
std::latch is a downward counter used to synchronize threads.
*/

#include <algorithm>
#include <cassert>
#include <deque>
#include <execution>
#include <functional>
#include <iostream>
#include <latch>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

void _worker(latch &syncPoint, int id)
{
    // simulate doing work
    this_thread::sleep_for(chrono::milliseconds(100));

    cout << "Thread " << id << " finished work and reached latch." << endl;

    // signal that this thread has reached the latch point
    syncPoint.count_down();

    // wait for all other threads to reach this point
    syncPoint.wait();

    cout << "Thread " << id << " is proceeding after latch." << endl;
}

void basic()
{
    const int numThreads = 5;
    latch syncPoint(numThreads); // latch initialized to count of threads

    vector<jthread> threads;

    // create and start threads
    for (int i = 0; i < numThreads; ++i)
    {
        threads.emplace_back(_worker, ref(syncPoint), i);
    }
}

int main()
{
    basic();

    cout << endl
         << __FILE__ " tests passed!" << endl;
    return 0;
}
