#include <gtest/gtest.h>

#include <vector>

/**
 * Suppose an array of length n sorted in ascending order is 'rotated' between '1' and 'n' times. For example, the
 * array 'nums = [0,1,2,4,5,6,7]' might become:
 *
 * - '[4,5,6,7,0,1,2]' if it was rotated '4' times.
 * - '[0,1,2,4,5,6,7]' if it was rotated '7' times.
 *
 * Notice that 'rotating' an array '[a[0], a[1], a[2], ..., a[n-1]]' 1 time results in the array
 * '[a[n-1], a[0], a[1], a[2], ..., a[n-2]]'.
 *
 * Given the sorted rotated array 'nums' of 'unique' elements, return the minimum element of this array.
 *
 * You must write an algorithm that runs in 'O(log n) time'.
 */

int32_t findMin(std::vector<int32_t>& nums) {
	// Set the result to be equal as the first element of the numbers array.
	int32_t res = nums[0];
	// Set the left and right pointers to the first and last elements of the array.
	int32_t l = 0, r = static_cast<int32_t>(nums.size()) - 1;
	// Stay in the loop while the left side is lower than the right side.
	while (l <= r) {
		// If a sorted sub array is found, then take the element from the left, since that is the lowest one.
		if (nums[l] <= nums[r]) {
			res = std::min(res, nums[l]);
			break;
		}
		// Otherwise, get the middle point and see if that point is higher or equal to the left, so the right subarray
		// can be taken.
		int32_t mid = (l + r) / 2;
		res = std::min(res, nums[mid]);
		if (nums[mid] >= nums[l]) {
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	return res;
}

TEST(PROBLEM_153, Example_1) {
	std::vector<int32_t> nums{ 3, 4, 5, 1, 2 };
	int32_t output = 1;
	ASSERT_EQ(findMin(nums), output);
}

TEST(PROBLEM_153, Example_2) {
	std::vector<int32_t> nums = { 4, 5, 6, 7, 0, 1, 2 };
	int32_t output = 0;
	ASSERT_EQ(findMin(nums), output);
}

TEST(PROBLEM_153, Example_3) {
	std::vector<int32_t> nums{ 11, 13, 15, 17 };
	int32_t output = 11;
	ASSERT_EQ(findMin(nums), output);
}
