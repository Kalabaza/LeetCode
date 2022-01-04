#include <gtest/gtest.h>

#include <algorithm>
#include <map>
#include <vector>

/**
 * Given two arrays, write a function to compute their intersection.
 */
std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::vector<int> res;
    std::map<int, int> nums;
    for(auto &num : nums1)
        ++nums[num];
    for(auto &num : nums2)
        if(nums.count(num) && --nums[num] >= 0)
            res.push_back(num);
    std::sort(res.begin(), res.end());
    return res;
}

TEST(PROBLEM_350, Example1) {
    std::vector<int> nums1{1,2,2,1};
    std::vector<int> nums2{2,2};
    std::vector<int> res{2,2};
    ASSERT_EQ(res, intersect(nums1, nums2));
}

TEST(PROBLEM_350, Example2) {
    std::vector<int> nums1{4,9,5};
    std::vector<int> nums2{9,4,9,8,4};
    std::vector<int> res{4,9};
    ASSERT_EQ(res, intersect(nums1, nums2));
}

TEST(PROBLEM_350, Example3) {
    std::vector<int> nums1{2,1};
    std::vector<int> nums2{1,2};
    std::vector<int> res{1,2};
    ASSERT_EQ(res, intersect(nums1, nums2));
}
