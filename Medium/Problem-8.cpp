#include <gtest/gtest.h>

#include <algorithm>
#include <string>

/**
 * Implement atoi which converts a string to an integer.
 *
 * The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting
 * from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them
 * as a numerical value.
 *
 * The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the
 * behavior of this function.
 *
 * If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either
 * str is empty or it contains only whitespace characters, no conversion is performed.
 *
 * If no valid conversion could be performed, a zero value is returned.
 */
int myAtoi(std::string str) {
    int res = 0;
    uint ind = 0;
    bool neg = false;
    bool pos = false;
    bool par = false;
    // discard all the whitespaces from the beggining of the string
    while(ind < str.size() && str[ind] == ' ')
        ++ind;
    int max = std::numeric_limits<int>::max() / 10;
    // now take the digits from the number to generate the result
    while(ind < str.size()) {
        // if the character is a number, add it to the current result
        if(str[ind] >= 48 && str[ind] <= 57) {
            // this means that an overlow or underflow will happen
            if(res > max)
                return neg ? std::numeric_limits<int>::min() : std::numeric_limits<int>::max();
            // in this case only a few digits are valid
            else if(res == max) {
                if(neg && (str[ind] - '0' == 9 || str[ind] - '0' == 8))
                    return std::numeric_limits<int>::min();
                else if(!neg && (str[ind] - '0' == 9 || str[ind] - '0' == 8))
                    return std::numeric_limits<int>::max();
            }
            par = true;
            // if there is no risk of overflow or underflow, simply do
            // the operation
            res = res * 10 + (str[ind] - '0');
        }
        // mark if the number has a negative or positive character
        else if(str[ind] == '-' || str[ind] == '+') {
            // check if there is any partial result so far, if so just
            // return that and ignore the symbol
            if(par)
                return neg ? -res : res;
            // this validation avoids using two signs in one string,
            //  that is simply not valid
            if(neg || pos)
                return 0;
            // the negative will be used at the end in the result
            else if(str[ind] == '-')
                neg = true;
            // the positive is just ignored, but still marked
            else
                pos = true;
        }
        // anyother character will terminate the conversion process
        else
            break;
        ++ind;
    }
    // if there was a negative sign, add that sign to the result
    return neg ? -res : res;
}

TEST(PROBLEM_8, Example1) {
    std::string input("42");
    ASSERT_EQ(42, myAtoi(input));
}

TEST(PROBLEM_8, Example2) {
    std::string input("   -42");
    ASSERT_EQ(-42, myAtoi(input));
}

TEST(PROBLEM_8, Example3) {
    std::string input("4193 with words");
    ASSERT_EQ(4193, myAtoi(input));
}

TEST(PROBLEM_8, Example4) {
    std::string input("words and 987");
    ASSERT_EQ(0, myAtoi(input));
}

TEST(PROBLEM_8, Example5) {
    std::string input("-91283472332");
    ASSERT_EQ(-2147483648, myAtoi(input));
}

TEST(PROBLEM_8, Example6) {
    std::string input("+");
    ASSERT_EQ(0, myAtoi(input));
}

TEST(PROBLEM_8, Example7) {
    std::string input("+-2");
    ASSERT_EQ(0, myAtoi(input));
}

TEST(PROBLEM_8, Example8) {
    std::string input("-2147483648");
    ASSERT_EQ(-2147483648, myAtoi(input));
}

TEST(PROBLEM_8, Example9) {
    std::string input("2147483648");
    ASSERT_EQ(2147483647, myAtoi(input));
}

TEST(PROBLEM_8, Example10) {
    std::string input("2147483646");
    ASSERT_EQ(2147483646, myAtoi(input));
}
