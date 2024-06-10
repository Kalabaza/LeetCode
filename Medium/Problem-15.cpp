#include <gtest/gtest.h>

#include <algorithm>
#include <vector>

/**
 * Given an integer array nums, return all the triplets '[nums[i], nums[j], nums[k]]' such that 'i != j', 'i != k',
 * and 'j != k', and 'nums[i] + nums[j] + nums[k] == 0'.
 *
 * Notice that the solution set must not contain duplicate triplets.
 */
std::vector<std::vector<int32_t>> threeSum(std::vector<int32_t>& nums) {
    std::vector<std::vector<int32_t>> result;
    // Sort the input data to ease the search of the results
    std::sort(nums.begin(), nums.end());
    for (size_t index = 0; index < nums.size(); ++index) {
        // If the current number is equal to the previous, go to the next number.
        if (index > 0 && nums[index] == nums[index - 1]) {
            continue;
        }
        // Take the numbers from the left and right borders
        size_t left = index + 1, right = nums.size() - 1;
        while (left < right) {
            int32_t sum = nums[index] + nums[left] + nums[right];
            // If the sum is higher than 0, then move the right pointer, since the data is sorted, the bigger numbers
            // are on the right, so a smaller number is needed.
            if (sum > 0) {
                --right;
            }
            // Otherwise, if the sum is lower than 0, a bigger number is needed, move the left pointer.
            else if (sum < 0) {
                ++left;
            }
            // When the sum is 0, save that numbers in the answer and move the left pointer to try getting a different
            // triplet.
            else {
                result.push_back(std::vector<int32_t>{nums[index], nums[left], nums[right]});
                ++left;
                while (nums[left] == nums[left - 1] && left < right) ++left;
            }
        }
    }
    return result;
}

TEST(PROBLEM_15, Example_1) {
    std::vector<int32_t> input{-1, 0, 1, 2, -1, -4};
    const std::vector<std::vector<int32_t>> output{{-1, -1, 2}, {-1, 0, 1}};
    ASSERT_EQ(output, threeSum(input));
}

TEST(PROBLEM_15, Example_2) {
    std::vector<int32_t> input{0, 1, 1};
    const std::vector<std::vector<int32_t>> output{};
    ASSERT_EQ(output, threeSum(input));
}

TEST(PROBLEM_15, Example_3) {
    std::vector<int32_t> input{0, 0, 0};
    const std::vector<std::vector<int32_t>> output{{0, 0, 0}};
    ASSERT_EQ(output, threeSum(input));
}