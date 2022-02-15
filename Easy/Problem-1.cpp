#include <gtest/gtest.h>

#include <map>
#include <vector>

/**
 * Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
 * 
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 *
 * You can return the answer in any order.
 */
std::vector<int32_t> twoSum(const std::vector<int32_t> &nums, int32_t target) {
    // A map will be used to save the difference of an specific
    // value and the target value. The index is saved in the map
    std::map<int32_t, int32_t> mapDiffs;
    // This vector will hold the result indexes
    std::vector<int32_t> result;
    // Go over all the numbers
    for(int32_t index = 0; index < nums.size(); ++index) {
        // Look for a value already on the map, such that in
        // addition with the current value is equal to the target
       int32_t diff = target - nums[index];
        if(mapDiffs.count(diff)) {
            // If found, save the indexes of the two values and
            // exit the loop
            result.push_back(mapDiffs[diff]);
            result.push_back(index);
            break;
        }
        // If there was not such value, add the current value
        // and its index to the map
        mapDiffs[nums[index]] = index;
    }
    // Return the vector with the indexes
    return result;
}

TEST(PROBLEM_1, Example1) {
    std::vector<int32_t> input{2,7,11,15};
    std::vector<int32_t> output{0,1};
    int32_t target = 9;
    ASSERT_EQ(output, twoSum(input, target));
}
