#include <gtest/gtest.h>

/**
 * There is an integer array 'nums' sorted in ascending order (with 'distinct' values).
 *
 * Prior to being passed to your function, 'nums' is 'possibly rotated' at an unknown pivot index 'k'
 * ('1 <= k < nums.length') such that the resulting array is
 * [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] ('0-indexed'). For example, '[0,1,2,4,5,6,7]'
 * might be rotated at pivot index '3' and become '[4,5,6,7,0,1,2]'.
 *
 * Given the array 'nums' 'after' the possible rotation and an integer 'target', return the index of 'target' if it is
 * in nums, or '-1' if it is not in 'nums'.
 *
 * You must write an algorithm with 'O(log n)' runtime complexity.
 */

int32_t search(std::vector<int32_t>& nums, int32_t target) {
    if (0 == nums.size()) return -1;
    int32_t left = 0, right = static_cast<int32_t>(nums.size()) - 1;
    while (left <= right) {
        int32_t middle = (left + right) / 2;
        if (target == nums[middle]) return middle;
        // The left side of the array is sorted
        if (nums[left] <= nums[middle]) {
            if (target > nums[middle] || target < nums[left])
                left = middle + 1;
            else
                right = middle - 1;
        }
        // The right side of the array is sorted
        else {
            if (target < nums[middle] || target > nums[right])
                right = middle - 1;
            else
                left = middle + 1;
        }
    }
    return -1;
}

TEST(PROBLEM_33, Example1) {
    std::vector<int32_t> nums{4, 5, 6, 7, 0, 1, 2};
    int32_t target = 0;
    constexpr int32_t output = 4;
    ASSERT_EQ(output, search(nums, target));
}

TEST(PROBLEM_33, Example2) {
    std::vector<int32_t> nums{4, 5, 6, 7, 0, 1, 2};
    int32_t target = 3;
    constexpr int32_t output = -1;
    ASSERT_EQ(output, search(nums, target));
}

TEST(PROBLEM_33, Example3) {
    std::vector<int32_t> nums{1};
    int32_t target = 0;
    constexpr int32_t output = -1;
    ASSERT_EQ(output, search(nums, target));
}

TEST(PROBLEM_33, Example4) {
    std::vector<int32_t> nums{};
    int32_t target = 0;
    constexpr int32_t output = -1;
    ASSERT_EQ(output, search(nums, target));
}
