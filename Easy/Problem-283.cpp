#include <gtest/gtest.h>

#include <vector>

/**
 * Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
 */
void moveZeroes(std::vector<int>& nums) {
    for(uint32_t cur = 0, lastNonZero = 0; cur < nums.size(); ++cur) {
         // find a non-zero value in the vector
         if(nums[cur] != 0)
             std::swap(nums[lastNonZero++], nums[cur]);
    }
}

void _moveZeroes2(std::vector<int>& nums) {
    for(uint32_t ind = 0, next; ind < nums.size(); ++ind) {
        // find a number zero in the vector
        if(nums[ind] == 0) {
            next = ind + 1;
            // now find the next position where there is not a zero
            while(next < nums.size() && nums[next] == 0) ++next;
            // if a valid next position was found, then swap the values
            // this will send the zero further to the end
            if(next < nums.size()) std::swap(nums[ind], nums[next]);
        }
    }
}

void _moveZeroes(std::vector<int>& nums) {
    for (uint32_t i = 1; i < nums.size(); ++i) {
		int current = nums[i];
		int j = i - 1;
		while (j >= 0 && nums[j] == 0) {
			nums[j + 1] = nums[j];
            --j;
		}
		nums[j + 1] = current;
	}
}

TEST(PROBLEM_283, Example1) {
    std::vector<int> input{0,1,0,3,12};
    std::vector<int> output{1,3,12,0,0};
    moveZeroes(input);
    ASSERT_EQ(output, input);
}

TEST(PROBLEM_283, Example2) {
    std::vector<int> input{4,2,4,0,0,3,0,5,1,0};
    std::vector<int> output{4,2,4,3,5,1,0,0,0,0};
    moveZeroes(input);
    ASSERT_EQ(output, input);
}
