#include <gtest/gtest.h>

#include <vector>

/**
 * You are given an integer array 'height' of length 'n'. There are 'n' vertical lines drawn such that the two
 * endpoints of the 'ith' line are '(i, 0)' and '(i, height[i])'.
 *
 * Find two lines that together with the x-axis form a container, such that the container contains the most water.
 *
 * Return the maximum amount of water a container can store.
 *
 * Notice that you may not slant the container.
 */

int32_t maxArea(const std::vector<int32_t>& height) {
   int32_t maximum = 0;
   // Using a left and right pointers at the start and end of the array of data
   int32_t left = 0, right = static_cast<int32_t>(height.size()) - 1;
   while(left != right) {
      // Save the maximum volume of water so far, to calculate the volume use the lowest height between the
      // left and right pointer with length between the left and right pointers
      maximum = std::max(maximum, (right - left) * std::min(height[left], height[right]));
      // Move the pointer with the lowest value
      if(height[left] < height[right])
         ++left;
      else
         --right;
   }
   return maximum;
}

TEST(PROBLEM_11, Example_1) {
   const std::vector<int32_t> input{1,8,6,2,5,4,8,3,7};
   constexpr int32_t output = 49;
   ASSERT_EQ(output, maxArea(input));
}

TEST(PROBLEM_11, Example_2) {
   const std::vector<int32_t> input{1,1};
   constexpr int32_t output = 1;
   ASSERT_EQ(output, maxArea(input));
}
