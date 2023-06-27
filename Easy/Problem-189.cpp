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
    // avoid going outside of the range from the vector,
    // having a k bigger than the size of the numbers only
    // means that the shift will wrap to the beginning as
    // much as needed
    k = k % nums.size();
    // cnt will repeat the process of swaping numbers as many times
    // as elments there are in the vector, start marks the begining of the cycle
    for (uint32_t cnt = 0, start = 0; cnt < nums.size(); ++start) {
        // this is the current index
       uint32_t cur = start;
        // and also the current element (that will become the previous)
        int prev = nums[start];
        do {
            // get the index of the next element that will be swap
           int32_t next = (cur + k) % nums.size();
            // save the content of that next index
            int temp = nums[next];
            // copy the previous element into this next location
            nums[next] = prev;
            // the current value will be saved for the next iteration
            prev = temp;
            // the new current is the next element
            cur = next;
            // increment the counter, to know if the end was reached
            ++cnt;
        // repeat the process while the cicle was not completed
        } while(start != cur);
    }
}

void _rotate2(std::vector<int>& nums, int k) {
    // reverse all the elements in the vector
    std::reverse(nums.begin(), nums.end());
    // now reverse from the begining to the desired position
    std::reverse(nums.begin(), nums.begin() + k);
    // finally reverse the rest of the numbers
    std::reverse(nums.begin() + k, nums.end());
}

void _rotate1(std::vector<int>& nums, int k) {
    while(k--) {
        // save the last element
        int tmp = nums[nums.size() - 1];
        // move the elements one position to the right
        for(size_t last = nums.size() - 1; last > 0; --last) {
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
