#include <gtest/gtest.h>

#include <algorithm>
#include <vector>

/**
 * Given an array, rotate the array to the right by k steps, where k is non-negative.
*
* Follow up:
*
* Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
* Could you do it in-place with O(1) extra space?
*/

void rotate(std::vector<int>& nums, int k) {
    // reverse all the elements in the vector
    std::reverse(nums.begin(), nums.end());
    // now reverse from the begining to the desired position
    std::reverse(nums.begin(), nums.begin() + k);
    // finally reverse the rest of the numbers
    std::reverse(nums.begin() + k, nums.end());
}

void _rotate(std::vector<int>& nums, int k) {
    while(k--) {
        // save the last element
        int tmp = nums[nums.size() - 1];
        // move the elements one position to the right
        for(uint last = nums.size() - 1; last > 0; --last) {
            nums[last] = nums[last - 1];
        }
        // now copy the saved element into the first position
        nums[0] = tmp;
    }
}

TEST(PROBLEM_189, Example1) {
    std::vector<int> input{1,2,3,4,5,6,7};
    std::vector<int> output{5,6,7,1,2,3,4};
    rotate(input, 3);
    ASSERT_EQ(output, input);
}

TEST(PROBLEM_189, Example2) {
    std::vector<int> input{-1,-100,3,99};
    std::vector<int> output{3,99,-1,-100};
    rotate(input, 2);
    ASSERT_EQ(output, input);
}
