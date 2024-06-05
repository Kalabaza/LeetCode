#include <gtest/gtest.h>

#include <map>
#include <vector>

/**
 * Given an array of integers 'nums' and an integer 'target', return indices of the two numbers such that they add up
 * to 'target'.
 *
 * You may assume that each input would have 'exactly one solution', and you may not use the same element twice.
 *
 * You can return the answer in any order.
 */
std::vector<int32_t> twoSum(const std::vector<int32_t>& nums, const int32_t target) {
	// A map is used to save the difference between one number and the target value as the index, the value is the
	// index of the element in the input vector.
	std::map<int32_t, int32_t> mapDiffs;
	// This vector will hold the result indexes
	std::vector<int32_t> result;
	for (int32_t index = 0; index < nums.size(); ++index) {
		// Look for a value already on the map, such that in addition with the current value is equal to the target.
		int32_t diff = target - nums[index];
		if (mapDiffs.count(diff)) {
			// If found, return a vector with the indexes of the found elements.
			return { mapDiffs[diff], index };
		}
		// If there was not such sum value, add the current value and its index to the map.
		mapDiffs[nums[index]] = index;
	}
	// This point will never be reached, so just return an empty vector.
	return {};
}

TEST(PROBLEM_1, Example_1) {
	const std::vector<int32_t> input{ 2,7,11,15 };
	const std::vector<int32_t> output{ 0,1 };
	constexpr int32_t target = 9;
	ASSERT_EQ(output, twoSum(input, target));
}

TEST(PROBLEM_1, Example_2) {
	const std::vector<int32_t> input{ 3,2,4 };
	const std::vector<int32_t> output{ 1,2 };
	constexpr int32_t target = 6;
	ASSERT_EQ(output, twoSum(input, target));
}

TEST(PROBLEM_1, Example_3) {
	const std::vector<int32_t> input{ 3,3 };
	const std::vector<int32_t> output{ 0,1 };
	constexpr int32_t target = 6;
	ASSERT_EQ(output, twoSum(input, target));
}
