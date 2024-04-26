/*
A future is an object that can retrieve a value in a way that is synchronized across threads
https://cplusplus.com/reference/future/future/
*/

#include <cassert>
#include <chrono>
#include <future>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void futureStatus()
{
    /*
    the future_status of a future is returned by wait_for and wait_until

    enum class future_status {
        ready,    // shared state is ready
        timeout,  // shared state did not become ready after wait_for
        deferred  // result will only be computed when explicitly requested
    };
    */
}

bool _isPrime(int n)
{
    for (int i = 2; i < n; ++i)
    {
        if (n % i == 0)
            return false;
    }

    return true;
}

// std::async abstracts away thread creation, providing a simpler interface
// but giving the developer less control
void asyncTest()
{
    // call _isPrime asynchronously
    future<bool> fut = std::async(launch::async, _isPrime, 144444457);

    // display status updates while waiting for the result
    cout << "checking";
    chrono::milliseconds span { 100 };
    while (fut.wait_for(span) == future_status::timeout)
        cout << ".";

    bool result = fut.get(); // retrieve return value
    assert(result);
    cout << "\nResult " << (result ? "is" : "is not") << " prime\n";
}

void asyncVector()
{
    constexpr int numThreads = 4;
    vector<future<bool>> v(numThreads);

    for (int i = 0; i < numThreads; ++i)
    {
        v[i] = async(launch::async, _isPrime, 144444457 + i);
    }

    assert(v[0].get());
    assert(!v[1].get());
    assert(!v[2].get());
    assert(!v[3].get());
}

void _worker(std::promise<int> &&promise)
{
    // simulate work
    this_thread::sleep_for(std::chrono::milliseconds(5));

    // set the result of the work
    promise.set_value(101);
}

// promises allow the developer to control thread creation
void promiseTest()
{
    promise<int> promise;

    // get the future object associated with the promise
    std::future<int> future = promise.get_future();

    // start a thread and pass in promise
    std::jthread t(_worker, std::move(promise));

    // wait for the result (this will block until the worker thread sets the value)
    int result = future.get();
    assert(result == 101);
}

void test()
{
    futureStatus();
    asyncTest();
    asyncVector();
    promiseTest();
}

int main()
{
    test();

    std::cout << std::endl <<  __FILE__ " tests passed!" << std::endl;
    return 0;
}
