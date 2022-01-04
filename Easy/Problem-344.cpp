#include <gtest/gtest.h>

#include <vector>

/**
 * Write a function that reverses a string. The input string is given as an array of characters char[].
 *
 * Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
 *
 * You may assume all the characters consist of printable ascii characters.
 */
void reverseString(std::vector<char>& s) {
    for(int i = 0, j = s.size() - 1; i < j; ++i, --j)
        std::swap(s[i], s[j]);
}

TEST(PROBLEM_344, Example1) {
    std::vector<char> input{'h', 'e', 'l', 'l', 'o'};
    std::vector<char> output{'o', 'l', 'l', 'e', 'h'};
    reverseString(input);
    ASSERT_EQ(output, input);
}

TEST(PROBLEM_344, Example2) {
    std::vector<char> input{'H', 'a', 'n', 'n', 'a', 'h'};
    std::vector<char> output{'h', 'a', 'n', 'n', 'a', 'H'};
    reverseString(input);
    ASSERT_EQ(output, input);
}
