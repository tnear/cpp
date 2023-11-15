/*
jthread - joining thread (C++20) - is the same as std::thread except jthread's
destructor automatically joins. std::thread terminates the program in its
destructor if join() or detach() had not been called.
https://en.cppreference.com/w/cpp/thread/jthread
*/

#include <cassert>
#include <iostream>
#include <thread>

using namespace std;

void _task()
{
    for (int i = 0; i < 3; ++i)
    {
        cout << "Running task... " << i << endl;
        this_thread::sleep_for(chrono::milliseconds(100));
    }
}

void basic()
{
    {
        jthread jt{_task}; // jthread joins automatically
        cout << "Exiting jthread scope\n";
    } // jt's destructor calls join()

    {
        thread t{_task}; // std::thread does not join automatically
        t.join();        // <-- without this explicit join(), the program terminates
                         // the thread's destructor
        cout << "Exiting thread scope\n";
    }
}

void test()
{
    basic();
}

int main()
{
    test();

    cout << endl
         << __FILE__ " tests passed!" << endl;
    return 0;
}
