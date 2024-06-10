#include <gtest/gtest.h>

#include <vector>

/**
 * Given an integer 'n', return an array 'ans' of length 'n + 1' such that for each 'i (0 <= i <= n), ans[i]' is the
 * 'number of 1's' in the binary representation of 'i'.
 */

std::vector<int32_t> countBits(int32_t n) {
    std::vector<int32_t> dp(n + 1, 0);
    // An offset is changed once a power of two change is detected, like going from 1 to 2, then 4, then 8 and so on.
    for (int32_t index = 1, offset = 1; index < n + 1; ++index) {
        if (offset * 2 == index) {
            offset = index;
        }
        // The current sum is equal to the previous sum of the past power of two plus one
        dp[index] = 1 + dp[index - offset];
    }
    return dp;
}

TEST(PROBLEM_338, Example1) {
    int32_t n = 2;
    std::vector<int32_t> output{0, 1, 1};
    ASSERT_EQ(output, countBits(n));
}

TEST(PROBLEM_338, Example2) {
    int32_t n = 5;
    std::vector<int32_t> output{0, 1, 1, 2, 1, 2};
    ASSERT_EQ(output, countBits(n));
}
