#include <gtest/gtest.h>

#include <vector>

/**
 * Given an integer array 'nums', find the 'subarray' with the largest sum, and return its sum.
 */

int32_t maxSubArray(std::vector<int32_t>& nums) {
    int32_t maxSub = nums[0];
    int32_t curSum = 0;
    for (const auto& num : nums) {
        // When there is a negative sum then start over, since having negative sum does not help to get the maximum
        // sub array sum.
        if (curSum < 0) {
            curSum = 0;
        }
        // Add the current value to the sum.
        curSum += num;
        // Save the max value found so far.
        maxSub = std::max(maxSub, curSum);
    }
    return maxSub;
}

TEST(PROBLEM_53, Example_1) {
    std::vector<int32_t> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int32_t output = 6;
    ASSERT_EQ(output, maxSubArray(nums));
}

TEST(PROBLEM_53, Example_2) {
    std::vector<int32_t> nums{1};
    int32_t output = 1;
    ASSERT_EQ(output, maxSubArray(nums));
}

TEST(PROBLEM_53, Example_3) {
    std::vector<int32_t> nums{5, 4, -1, 7, 8};
    int32_t output = 23;
    ASSERT_EQ(output, maxSubArray(nums));
}
