#include <gtest/gtest.h>

/**
 * You are climbing a staircase. It takes 'n' steps to reach the top.
 *
 * Each time you can either climb '1' or '2' steps. In how many distinct ways can you climb to the top?
 */

int32_t climbStairs(int32_t n) {
    // Use two variables to compute the one and two steps count.
    int32_t one = 1, two = 1;
    for (int32_t i = 0; i < n - 1; ++i) {
        // Save the one count.
        int32_t tmp = one;
        // Add the two counts together.
        one = one + two;
        // The second count is equal to the saved count from one.
        two = tmp;
    }
    // Return what is contained in the first count.
    return one;
}

int32_t climbStairsOld(int32_t n) {
    if (n <= 2) {
        return n;
    }

    int32_t oneStep = 1, twoSteps = 2;
    int32_t nthStep = 0;
    for (int i = 3; i <= n; ++i) {
        nthStep = oneStep + twoSteps;
        oneStep = twoSteps;
        twoSteps = nthStep;
    }
    return nthStep;
}

TEST(PROBLEM_70, Example1) {
    int32_t n = 2;
    int32_t output = 2;
    ASSERT_EQ(output, climbStairs(n));
}

TEST(PROBLEM_70, Example2) {
    int32_t n = 3;
    int32_t output = 3;
    ASSERT_EQ(output, climbStairs(n));
}
