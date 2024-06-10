#include <gtest/gtest.h>

#include <vector>

/**
 * Given an array "nums" containing "n" distinct numbers in the range "[0, n]", return the only number in the range that
 * is missing from the array.
 */

int32_t missingNumber(std::vector<int32_t>& nums) {
    int32_t sum = static_cast<int32_t>(nums.size());
    for (int32_t index = 0; index < nums.size(); ++index) {
        sum += (index - nums[index]);
    }
    return sum;
}
TEST(PROBLEM_268, Example1) {
    std::vector<int32_t> nums = {3, 0, 1};
    int32_t output = 2;
    ASSERT_EQ(output, missingNumber(nums));
}

TEST(PROBLEM_268, Example2) {
    std::vector<int32_t> nums = {0, 1};
    int32_t output = 2;
    ASSERT_EQ(output, missingNumber(nums));
}

TEST(PROBLEM_268, Example3) {
    std::vector<int32_t> nums = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    int32_t output = 8;
    ASSERT_EQ(output, missingNumber(nums));
}
