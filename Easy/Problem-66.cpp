#include <gtest/gtest.h>

#include <vector>

/**
 * Given a non-empty array of digits representing a non-negative integer, plus one to the integer.
 *
 * The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.
 *
 * You may assume the integer does not contain any leading zero, except the number 0 itself.
 */
std::vector<int> plusOne(std::vector<int>& digits) {
    // copy the original vector locally
    std::vector<int> res(digits);
    // if the last digit of the number is 9, then there will be an overflow, see how deep that overflow goes
    if(res[res.size() - 1] == 9) {
        bool overflow = true;
        // put zero in the last digit
        res[res.size() - 1] = 0;
        // start the loop from the second last digit, and repeat as long as there is an overflow
        for(int ind = res.size() - 2; overflow && ind >= 0; --ind) {
            // if the current number is 9, then the over flow continues
            if(res[ind] == 9)
                res[ind] = 0;
            // when having other value different than 9, the overflow ends and just incriment
            // the current number
            else {
                ++res[ind];
                overflow = false;
            }
        }
        // is there still an overflow? this means that the digit one has to be inserted in the vector
        if(overflow)
            res.insert(res.begin(), 1);
    }
    // this is the simplest solution, just add one to the last number
    else
        ++res[res.size() - 1];
    return res;
}

TEST(PROBLEM_66, Example1) {
    std::vector<int> input{1,2,3};
    std::vector<int> output{1,2,4};
    ASSERT_EQ(output, plusOne(input));
}

TEST(PROBLEM_66, Example2) {
    std::vector<int> input{4,3,2,1};
    std::vector<int> output{4,3,2,2};
    ASSERT_EQ(output, plusOne(input));
}

TEST(PROBLEM_66, Example3) {
    std::vector<int> input{9};
    std::vector<int> output{1,0};
    ASSERT_EQ(output, plusOne(input));
}
