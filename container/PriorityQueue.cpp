// Priority queues (heaps) are designed such that its first element is always the greatest
// of the elements it contains, according to some strict weak ordering criterion.
// Default behavior is to create a max heap.
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

    // create a priority queue of type int (max heap)
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

void getKLargest()
{
    vector<int> values = {5, 6, 7, 2, 1, 3, 9, 4, 8};
    const int k = 3; // track the 3 largest

    // getting the k largest requires a *min* queue (not a max queue)
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int value : values)
    {
        if (minHeap.size() < k)
        {
            // add everything if we haven't reached k elements
            minHeap.push(value);
        }
        else if (value > minHeap.top())
        {
            // found a larger value than than the current smallest
            // remove current smallest then add this new number
            minHeap.pop();
            minHeap.push(value);
        }
    }

    vector<int> exp = {7, 8, 9};
    vector<int> act;
    while (!minHeap.empty())
    {
        int elem = minHeap.top();
        act.push_back(elem);
        minHeap.pop();
    }

    assert(act == exp);
}

void comparisonFunction()
{
    // for anything more complex than std::greater, std::greater_equal, std::less, etc.
    // use this syntax:

    // compare pair<int, int>
    auto fcn = [](pair<int, int> &left, pair<int, int> &right)
    {
        return left.first > right.first;
    };

    //             <data type>     vector<data type>      <comp fcn type>        <fcn>
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(fcn)> minHeap(fcn);

    pair<int, int> p = {2, 3};
    minHeap.push(p);
    p = {1, 4};
    minHeap.push(p);

    pair<int, int> top = minHeap.top();
    assert(top.first == 1 && top.second == 4);
}

void test()
{
    constructor();
    top();
    minHeap();
    getKLargest();
    comparisonFunction();
}

int main()
{
    test();

    std::cout << "\n" <<  __FILE__ " tests passed!" << std::endl;
    return 0;
}
