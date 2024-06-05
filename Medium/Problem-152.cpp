#include <gtest/gtest.h>

#include <algorithm>
#include <vector>

/**
 * Given an integer array 'nums', find a 'subarray' that has the largest product, and return the product.
 *
 * The test cases are generated so that the answer will fit in a '32-bit' integer.
 */

int32_t maxProduct(std::vector<int32_t>& nums) {
	// The max product is initialized with the maximum element from the vector.
	int32_t maxProd = *std::max_element(nums.begin(), nums.end());
	int32_t curMin = 1, curMax = 1;
	for (const auto& num : nums) {
		if (num == 0) {
			curMin = curMax = 1;
			continue;
		}
		// The current max and min values are save, since by changing the sign of the number a negative can become
		// positive and thus a new maximum can be found.
		int32_t tmpMax = curMax * num;
		curMax = std::max(tmpMax, std::max(curMin * num, num));
		curMin = std::min(tmpMax, std::min(curMin * num, num));
		maxProd = std::max(maxProd, curMax);
	}
	return maxProd;
}

TEST(PROBLEM_152, Example_1) {
	std::vector<int32_t> nums{ 2, 3, -2, 4 };
	int32_t output = 6;
	ASSERT_EQ(maxProduct(nums), output);
}

TEST(PROBLEM_152, Example_2) {
	std::vector<int32_t> nums{ -2, 0, -1 };
	int32_t output = 0;
	ASSERT_EQ(maxProduct(nums), output);
}