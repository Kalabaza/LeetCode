#include <gtest/gtest.h>

#include <vector>

/**
 * Given an integer array 'nums', return an array 'answer' such that 'answer[i]' is equal to the product of all the
 * elements of 'nums' except 'nums[i]'.
 *
 * The product of any prefix or suffix of 'nums' is 'guaranteed' to fit in a '32-bit' integer.
 *
 * You must write an algorithm that runs in 'O(n)' time and without using the division operation.
 */

std::vector<int32_t> productExceptSelf(std::vector<int32_t>& nums) {
    std::vector<int32_t> result(nums.size(), 1);
    int prefix = 1;
    // Calculate the prefix multiplication and save the value in the resulting vector, multiply the previous values
    // and save this multiplication in the current position, the current value is not used in this multiplication.
    for (int32_t index = 0; index < nums.size(); ++index) {
        result[index] = prefix;
        prefix *= nums[index];
    }
    int postfix = 1;
    // Now do the same but starting from the end of the array, multiply all the values with the current postfix but not
    // using the current position.
    for (int32_t index = static_cast<int32_t>(nums.size()) - 1; index >= 0; --index) {
        result[index] *= postfix;
        postfix *= nums[index];
    }
    return result;
}

TEST(PROBLEM_238, Example1) {
    std::vector<int32_t> nums{1, 2, 3, 4};
    std::vector<int32_t> output{24, 12, 8, 6};
    ASSERT_EQ(productExceptSelf(nums), output);
}

TEST(PROBLEM_238, Example2) {
    std::vector<int32_t> nums{-1, 1, 0, -3, 3};
    std::vector<int32_t> output{0, 0, 9, 0, 0};
    ASSERT_EQ(productExceptSelf(nums), output);
}
