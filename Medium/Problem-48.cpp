#include <gtest/gtest.h>

#include <vector>

/**
 * You are given an n x n 2D matrix representing an image.
 *
 * Rotate the image by 90 degrees (clockwise).
 */
void rotate(std::vector<std::vector<int32_t>>& matrix) {
    // this is the maximum index that a value can use
   int32_t size = matrix.size() - 1;
    // will work on levels on the matrix, the most outer level is the number 0
    for(int32_t level = 0; level < matrix.size() / 2; ++level) {
        // this will iterate thru the values
        for(int32_t ind = level; ind < size - level; ++ind) {
            // save the value from the upper left position for later
           int32_t tmp = matrix[level][ind];

            // copy the lower left value to the upper left position
            matrix[level][ind] = matrix[size - ind][level];

            // copy the lower right value to the lower left position
            matrix[size - ind][level] = matrix[size - level][size - ind];

            // copy the upper right value to the lower right position
            matrix[size - level][size - ind] = matrix[ind][size - level];

            // finally copy the saved value to the upper right position
            matrix[ind][size - level] = tmp;
        }
    }
}

TEST(PROBLEM_48, Example1) {
    std::vector<std::vector<int32_t>> input{
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    std::vector<std::vector<int32_t>> output{
        {7,4,1},
        {8,5,2},
        {9,6,3}
    };
    rotate(input);
    ASSERT_EQ(output, input);
}

TEST(PROBLEM_48, Example2) {
    std::vector<std::vector<int32_t>> input{
        { 5, 1, 9,11},
        { 2, 4, 8,10},
        {13, 3, 6, 7},
        {15,14,12,16}
    };
    std::vector<std::vector<int32_t>> output{
        {15,13, 2, 5},
        {14, 3, 4, 1},
        {12, 6, 8, 9},
        {16, 7,10,11}
    };
    rotate(input);
    ASSERT_EQ(output, input);
}
