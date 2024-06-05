#include <gtest/gtest.h>

#include <set>
#include <vector>

/**
 * Given an integer array 'nums', return 'true' if any value appears 'at least twice' in the array, and return 'false'
 * if every element is distinct.
 */

bool containsDuplicate(std::vector<int32_t>& nums) {
	// A set will be used to save the numbers already found in the vector.
	std::set<int32_t> found;
	for (const auto& num : nums) {
		// Check if the number was already found, meaning that it is a duplicate.
		if (0 != found.count(num)) {
			return true;
		}
		// The number was not found, so now add it to the set.
		found.insert(num);
	}
	// There was not a duplicated number in the vector
	return false;
}

TEST(PROBLEM_217, Example1) {
	std::vector<int32_t> nums{ 1,2,3,1 };
	ASSERT_TRUE(containsDuplicate(nums));
}

TEST(PROBLEM_217, Example2) {
	std::vector<int32_t> nums{ 1,2,3,4 };
	ASSERT_FALSE(containsDuplicate(nums));
}

TEST(PROBLEM_217, Example3) {
	std::vector<int32_t> nums{ 1,1,1,3,3,4,3,2,4,2 };
	ASSERT_TRUE(containsDuplicate(nums));
}

TEST(PROBLEM_217, Example4) {
	std::vector<int32_t> nums{ 1,5,-2,-4,0 };
	ASSERT_FALSE(containsDuplicate(nums));
}
