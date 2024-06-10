#include <gtest/gtest.h>

/**
 * Write a function that takes the binary representation of a positive integer and returns the number of 'set bits' it
 * has (also known as the 'Hamming weight').
 */

int32_t hammingWeight(int32_t n) {
    int32_t count = 0;
    // While the number is not zero, see if the last bit is 1 or 0, with the modulo operator.
    while (n) {
        count += n % 2;
        // Do a shift displacement of the number to make it smaller.
        n >>= 1;
    }
    return count;
}

TEST(PROBLEM_191, Example1) {
    int32_t n = 11;
    int32_t output = 3;
    ASSERT_EQ(output, hammingWeight(n));
}

TEST(PROBLEM_191, Example2) {
    int32_t n = 128;
    int32_t output = 1;
    ASSERT_EQ(output, hammingWeight(n));
}

TEST(PROBLEM_191, Example3) {
    int32_t n = 2147483645;
    int32_t output = 30;
    ASSERT_EQ(output, hammingWeight(n));
}
