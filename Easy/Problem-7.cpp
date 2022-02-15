#include <gtest/gtest.h>

/**
 * Given a 32-bit signed integer, reverse digits of an integer.
 */
int32_t reverse(int32_t x) {
   int32_t res = 0;
    // check if the received number is negative
    bool negative = false;
    if(x < 0) {
        // there is one special case of a negative number, which cannot be converted to positive,
        // so take care of that before doing any calculation
        if(x == std::numeric_limits<int32_t>::min())
            return 0;
        // the rest of the negatives can be changed to positive to make it easier to work
        negative = true;
        x *= -1;
    }
    int32_t max = std::numeric_limits<int32_t>::max() / 10;
    // now take each digit from the number and add it into the new number in reverse order
    while(x) {
        // if the resulting number will overflow or underflow, just return 0
        if(res > max)
            return 0;
        // first multiply the current value by 10 and add the new digit at the start
        res = res * 10 + x % 10;
        // remove the last digit from the original number and continue with the next one
        x /= 10;
    }
    // if the original number was negative, change the sign of the result
    return negative ? res * -1 : res;
}

TEST(PROBLEM_7, Example1) {
   int32_t input = 123;
   int32_t output = 321;
    ASSERT_EQ(output, reverse(input));
}

TEST(PROBLEM_7, Example2) {
   int32_t input = -123;
   int32_t output = -321;
    ASSERT_EQ(output, reverse(input));
}

TEST(PROBLEM_7, Example3) {
   int32_t input = 120;
   int32_t output = 21;
    ASSERT_EQ(output, reverse(input));
}

TEST(PROBLEM_7, Example4) {
   int32_t input = 1534236469;
   int32_t output = 0;
    ASSERT_EQ(output, reverse(input));
}

TEST(PROBLEM_7, Example5) {
   int32_t input = -2147483647 - 1;
   int32_t output = 0;
    ASSERT_EQ(output, reverse(input));
}

TEST(PROBLEM_7, Example6) {
   int32_t input = -2147483647;
   int32_t output = 0;
    ASSERT_EQ(output, reverse(input));
}
