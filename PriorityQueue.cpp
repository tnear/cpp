// Priority queues (heaps) are designed such that its first element is always the greatest
// of the elements it contains, according to some strict weak ordering criterion.
// https://cplusplus.com/reference/queue/priority_queue/

#include <cassert>
#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

void constructor()
{
    // range constructor uses iterators and preallocates
    std::vector<int> v = {2, 1, 4, 6, 0, 3};

    // create a priority queue of type int
    // (default container of vector<T> and comparator as std::less<T>)
    priority_queue<int> pq = {v.begin(), v.end()};
    assert(pq.size() == 6);

    // can also use push()
    priority_queue<int> pq2;
    pq2.push(1);
    pq2.push(2);
    pq2.push(3);
    assert(pq2.size() == 3);
}

void top()
{
    std::vector<int> v = {2, 1, 4, 6, 0, 3};
    priority_queue<int> pq = {v.begin(), v.end()};

    assert(pq.size() == v.size());
    vector<int> result;

    // MaxHeap: get highest priority down to lowest
    while (!pq.empty())
    {
        // get top element
        int elem = pq.top();
        result.push_back(elem);

        // remove top element
        pq.pop();
    }

    assert(pq.empty());
    vector<int> expData = {6, 4, 3, 2, 1, 0};
    // verify order
    assert(result == expData);
}

void minHeap()
{
    std::vector<int> v = {2, 1, 4, 6, 0, 3};

    // create a min heap by using std::greater<int>
    // this also specifies an underlying vector<int> container
    priority_queue<int, vector<int>, greater<int>> minHeap = {v.begin(), v.end()};

    vector<int> result;
    while (!minHeap.empty())
    {
        int elem = minHeap.top();
        result.push_back(elem);
        minHeap.pop();
    }

    // data is now lowest to highest due to using std::greater<T>
    vector<int> expData = {0, 1, 2, 3, 4, 6};
    assert(result == expData);    
}

void test()
{
    constructor();
    top();
    minHeap();
}

int main()
{
    test();

    std::cout << "\n" <<  __FILE__ " tests passed!" << std::endl;
    return 0;
}
