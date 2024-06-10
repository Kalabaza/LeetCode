#include <gtest/gtest.h>

/**
 * Reverse bits of a given 32 bits unsigned integer.
 */

uint32_t reverseBits(uint32_t n) {
    uint32_t res = 0;
    // There are only 32 bits to process, so use and index to iterate over all of them.
    for (int index = 0; index < 32; ++index) {
        // The result number is formed with the bit in the index position shifted in the other direction (31 - index).
        res |= ((n >> index) & 1) << (31 - index);
    }
    return res;
}

TEST(PROBLEM_190, Example1) {
    uint32_t n = 43261596;
    uint32_t output = 964176192;
    ASSERT_EQ(output, reverseBits(n));
}

TEST(PROBLEM_190, Example2) {
    uint32_t n = 4294967293;
    uint32_t output = 3221225471;
    ASSERT_EQ(output, reverseBits(n));
}
