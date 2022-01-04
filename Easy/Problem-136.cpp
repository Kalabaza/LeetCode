#include <gtest/gtest.h>

#include <set>
#include <vector>

/**
 * Given a non-empty array of integers, every element appears twice except for one. Find that single one.
 *
 * Note:
 *
 * Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
 */
int singleNumber(std::vector<int>& nums) {
    // using a set to temporary hold the numbers from the vector
    std::set<int> found;
    // go over all the numbers from the vector
    for(auto &num : nums) {
        // if the number is already in the set, remove it
        if(found.count(num) != 0) {
            found.erase(num);
        }
        // otherwise add that number to the set
        else {
            found.insert(num);
        }
    }
    // the only number that should be left in the set is the
    // number that is not duplicated, all the other ones were
    // already removed
    return *found.begin();
}

int _singleNumber(std::vector<int>& nums) {
    int missing = 0;
    for(auto &num : nums) {
        missing ^= num;
    }
    return missing;
}

TEST(PROBLEM_136, Example1) {
    std::vector<int> nums{2,2,1};
    ASSERT_EQ(1, singleNumber(nums));
}

TEST(PROBLEM_136, Example2) {
    std::vector<int> nums{4,1,2,1,2};
    ASSERT_EQ(4, singleNumber(nums));
}

TEST(PROBLEM_136, NegativeNumbers) {
    std::vector<int> nums{4,-1,2,-1,2};
    ASSERT_EQ(4, singleNumber(nums));
}
