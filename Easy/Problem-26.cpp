#include <gtest/gtest.h>

#include <vector>

/**
 * Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.
 *
 * Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
 */
int removeDuplicates(std::vector<int>& nums) {
    // if the vector is empty, just return 0
    if (0 == nums.size())
        return 0;

    // variables to hold the current and next valid index in the array
    int32_t cur = 0;
    uint32_t next = 1;
    // go all over all the elements in the vector
    while(next < nums.size()) {
        // check if the current and next element are equal
        if(nums[cur] == nums[next]) {
            // while there are equal, move the next element until
            // one that is different is found
            // Note: first check that there is an valid element to
            // compare against
            while(++next < nums.size() && nums[cur] == nums[next]) {}
        }
        // if we didn't reach the end of the vector, copy the next
        // different element to the position after the current valid
        if(next < nums.size())
            nums[++cur] = nums[next++];
    }
    // return the current position plus one (since the vector indexes
    // start in 0)
    return cur + 1;
}

bool compareVectors(std::vector<int32_t> &a, std::vector<int32_t> &b, int32_t length) {
    bool res = true;
    for(int32_t ind = 0; ind < length && res; ++ind) {
        if(a[ind] != b[ind])
            res = false;
    }
    return res;
}

TEST(PROBLEM_26, Example1) {
    std::vector<int32_t> input{1,1,2};
    std::vector<int32_t> output{1,2};
    int32_t length = removeDuplicates(input);
    ASSERT_EQ(2, length);
    ASSERT_TRUE(compareVectors(input, output, length));
}

TEST(PROBLEM_26, Example2) {
    std::vector<int32_t> input{0,0,1,1,1,2,2,3,3,4};
    std::vector<int32_t> output{0,1,2,3,4};
    int32_t length = removeDuplicates(input);
    ASSERT_EQ(5, length);
    ASSERT_TRUE(compareVectors(input, output, length));
}

TEST(PROBLEM_26, EmptyData) {
    std::vector<int32_t> input{};
    ASSERT_EQ(0, removeDuplicates(input));
}

TEST(PROBLEM_26, OnlyOneNumberButDuplicated) {
    std::vector<int32_t> input{1,1};
    std::vector<int32_t> output{1};
    int32_t length = removeDuplicates(input);
    ASSERT_EQ(1, length);
    ASSERT_TRUE(compareVectors(input, output, length));
}
