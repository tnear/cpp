/*
<bit> C++20 header for bit computations
https://en.cppreference.com/w/cpp/header/bit
*/

#include <algorithm>
#include <bit>
#include <cassert>
#include <iostream>
#include <string>

using namespace std;

void popcount()
{
    // popcount() returns the number of 1s in a number
    unsigned num = 0b10110011;

    int count = std::popcount(num);
    assert(count == 5);

    num = 6; // 0b110
    count = std::popcount(num);
    assert(count == 2);
}

void endianTest()
{
    static_assert(std::endian::native == std::endian::little);
}

// Bit index is the index of the bit going right to left
// ex: number: 0000 0000
//  bit index: 7654 3210
bool getBit(int number, int bitIndex)
{
    // create a mask containing a single bit shifted
    int mask = 1 << bitIndex;

    // AND the mask with the number to extract just that bit
    int bit = number & mask;

    return bit;
}

int setBit(int number, int bitIndex)
{
    // create a mask containing a single bit shifted
    int mask = 1 << bitIndex;

    // OR the mask with the number to ensure that bit is set
    int result = number | mask;

    return result;
}

// this sets bitIndex to zero (regardless of its current value)
int clearBit(int number, int bitIndex)
{
    // create ...00100...
    int mask = 1 << bitIndex;

    // use the bitwise NOT operator to invert all bits which creates ...11011...
    mask = ~mask;

    // AND with mask to clear just the one bit
    int result = number & mask;

    return result;
}

// clears these 'x' bits when i = 4:
// num = 111x xxxx
//(idx = 7654 3210)
int clearBits0ThroughI(int num, int i)
{
    // create all 1s
    int mask = ~0;

    // create ...111000...
    // +1 is needed because clearing the zero bit requires one shift
    mask <<= (i + 1);

    int result = num & mask;
    return result;
}

int clearBitsIThroughMSB(int num, int i)
{
    // create all 1s
    int mask = ~0;

    // create ...111000...
    mask <<= i;

    // invert to create ...000111...
    mask = ~mask;

    int result = num & mask;
    return result;
}

void testGetBit()
{
    int num = 0b0100;

    // bit zero is not set
    bool b = getBit(num, 0);
    assert(!b);

    // bit one is not set
    b = getBit(num, 1);
    assert(!b);

    // bit two is set
    b = getBit(num, 2);
    assert(b);

    // bit three is not set
    b = getBit(num, 3);
    assert(!b);

    // bits 4+ are not set
    b = getBit(num, 4);
    assert(!b);
}

void testSetBit()
{
    int num = 0b0100;

    int result = setBit(num, 0);
    assert(result == 5);

    result = setBit(num, 1);
    assert(result == 6);

    result = setBit(num, 2);
    assert(result == num && result == 4);

    result = setBit(num, 3);
    assert(result == 12);

    // set a higher bit (4)
    // setting an unset bit increases the total value by 2^4
    result = setBit(num, 4);
    assert(result == 20);
}

void testClearBit()
{
    int num = 0b0110;

    int result = clearBit(num, 0);
    assert(result == 6);

    result = clearBit(num, 1);
    assert(result == 4);

    result = clearBit(num, 2);
    assert(result == 2);

    result = clearBit(num, 3);
    assert(result == 6);

    result = clearBit(num, 4);
    assert(result == 6);
}

void testClearBits0ThroughI()
{
    int num = 0b1011;

    int result = clearBits0ThroughI(num, 0);
    assert(result == 10);

    result = clearBits0ThroughI(num, 1);
    assert(result == 8);

    result = clearBits0ThroughI(num, 2);
    assert(result == 8);

    result = clearBits0ThroughI(num, 3);
    assert(result == 0);
}

void testClearBitsIThroughMSB()
{
    int num = 0b1011;

    int result = clearBitsIThroughMSB(num, 0);
    assert(result == 0);

    result = clearBitsIThroughMSB(num, 1);
    assert(result == 1);

    result = clearBitsIThroughMSB(num, 2);
    assert(result == 3);

    result = clearBitsIThroughMSB(num, 3);
    assert(result == 3);

    result = clearBitsIThroughMSB(num, 4);
    assert(result == 11);
}

void rotateTest()
{
    unsigned num = 0b10011001100110011001100110011001;

    // left rotation by 1
    unsigned result = std::rotl(num, 1);
    assert(result == 0b00110011001100110011001100110011);

    // right rotation by 2
    result = std::rotr(num, 2);
    assert(result == 0b01100110011001100110011001100110);
}

void test()
{
    // C++20 tests
    popcount();
    endianTest();
    rotateTest();

    // pre-C++20 tests (do not use <bit> header)
    testGetBit();
    testSetBit();
    testClearBit();
    testClearBits0ThroughI();
    testClearBitsIThroughMSB();
}

int main()
{
    test();

    std::cout << std::endl <<  __FILE__ " tests passed!" << std::endl;
    return 0;
}
