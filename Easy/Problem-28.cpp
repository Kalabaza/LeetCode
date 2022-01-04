#include <gtest/gtest.h>

#include <string>

/**
 * Implement strStr().
 *
 * Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
 */

int strStr(std::string haystack, std::string needle) {
    uint n = needle.size();
    // if the needle is an empty string, just retrun 0 per convention
    if(n == 0)
        return 0;
    uint h = haystack.size();
    // only do the validation if the needle is shorter than or equal in size to the haystack
    if(n <= h) {
        // Go all over the text from the haystack until the first letter of the needle is found
        // but take in consideration the size of the needle to avoid checking positions that will
        // not work (remaining characters with a size lower than the needle)
        for(uint i = 0; i <= h - n; ++i) {
            // Then, when this letter is found search for the rest of the needle
            if(haystack[i] == needle[0]) {
                for(uint j = 0; j < n; ++j) {
                    // As soon as one character is not equal exit this loop
                    if(haystack[i + j] != needle[j])
                        break;
                    // If the complete needle was found return the position of the first character
                    // on the main text
                    if(j == needle.size() - 1)
                        return i;
                }
            }
        }
    }
    // if the needle was not found of the size is bigger than the haystack, return error
    return -1;
}

TEST(PROBLEM_28, Example1) {
    std::string haystack{"hello"};
    std::string needle{"ll"};
    ASSERT_EQ(2, strStr(haystack, needle));
}

TEST(PROBLEM_28, Example2) {
    std::string haystack{"aaaaa"};
    std::string needle{"bba"};
    ASSERT_EQ(-1, strStr(haystack, needle));
}
