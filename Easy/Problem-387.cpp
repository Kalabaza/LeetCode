#include <gtest/gtest.h>

#include <map>
#include <string>

/**
 * Given a string, find the first non-repeating character in it and return its index. If it doesn't exist, return -1.
 */
int32_t firstUniqChar(std::string s) {
    // a map will be used to count the occurences of the characters in the whole string
    std::map<char, int32_t> letters;
    for(auto &c : s)
        ++letters[c];
    // now go over the string to see which letter appears only once in that string
    for(uint32_t i = 0; i < s.size(); ++i) {
        // if found, return the current position on the string
        if(letters[s[i]] == 1)
            return i;
    }
    // if there is not a character that appears only once, return -1
    return -1;
}

TEST(PROBLEM_387, Example1) {
    std::string input("leetcode");
    ASSERT_EQ(0, firstUniqChar(input));
}

TEST(PROBLEM_387, Example2) {
    std::string input("loveleetcode");
    ASSERT_EQ(2, firstUniqChar(input));
}
