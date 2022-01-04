#include <gtest/gtest.h>

#include <set>
#include <vector>

/**
 * Given an array of integers, find if the array contains any duplicates.
 *
 * Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.
 */

bool containsDuplicate(std::vector<int>& nums) {
    // a set will be used to save the numbers already found in the vector
    std::set<int> found;
    for(auto &num : nums) {
        // check if the number was already found, meaning that it
        // is duplicated
        if(found.count(num) != 0) {
            return true;
        }
        // the number was not found, so now add it to the set
        found.insert(num);
    }
    // there was not a duplicated number in the vector
    return false;
}

bool _containsDuplicate(std::vector<int>& nums) {
    // using an integer as a binary array, having a bit turn on means
    // that a number was already found in the vector. It is initalized
    // to zero in all the positions.
    int found = 0;
    for(auto &num : nums) {
        // take each number from the arry and check if it was already seen
        if(found & 1 << num) {
            // if the number is found, return true and exit the loop
            return true;
        }
        // if the number was not found, mark it now so it can be found later
        found |= 1 << num;
    }
    // number not found, return false after checking all the numbers
    return false;
}

TEST(PROBLEM_217, Example1) {
    std::vector<int> nums{1,2,3,1};
    ASSERT_TRUE(containsDuplicate(nums));
}

TEST(PROBLEM_217, Example2) {
    std::vector<int> nums{1,2,3,4};
    ASSERT_FALSE(containsDuplicate(nums));
}

TEST(PROBLEM_217, Example3) {
    std::vector<int> nums{1,1,1,3,3,4,3,2,4,2};
    ASSERT_TRUE(containsDuplicate(nums));
}

TEST(PROBLEM_217, Example4) {
    std::vector<int> nums{1,5,-2,-4,0};
    ASSERT_FALSE(containsDuplicate(nums));
}
