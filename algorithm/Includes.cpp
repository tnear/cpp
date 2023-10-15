// Test whether sorted range includes another sorted range
// https://cplusplus.com/reference/algorithm/includes/
// bool includes(InputIterator1 first1, InputIterator1 last1,
//               InputIterator2 first2, InputIterator2 last2);

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

// note: both ranges must be sorted
void testBasic()
{
    vector<int> v1 = {1, 2, 3, 4, 5};
    vector<int> v2 = {2, 3, 4};
    vector<int> v3 = {2, 3, 5};
    vector<int> v4 = {2, 3, 6};

    // the elements {2, 3, 4} are all in v1
    bool result = std::includes(v1.begin(), v1.end(), v2.begin(), v2.end());
    assert(result);

    // the elements {2, 3, 5} are also all in v1 (they do not need to be consecutive)
    result = std::includes(v1.begin(), v1.end(), v3.begin(), v3.end());
    assert(result);

    // the elements {2, 3, 6} are NOT in v1
    result = std::includes(v1.begin(), v1.end(), v4.begin(), v4.end());
    assert(!result);
}

void test()
{
    testBasic();
}

int main()
{
    test();

    std::cout << std::endl <<  __FILE__ " tests passed!" << std::endl;
    return 0;
}
