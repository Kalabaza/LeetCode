#include <gtest/gtest.h>

#include <algorithm>
#include <string>

/**
 * Given two strings s and t, write a function to determine if t is an anagram of s.
 */
bool isAnagram(std::string s, std::string t) {
    // for simplicity, the two strings will be sorted
    std::sort(s.begin(), s.end());
    std::sort(t.begin(), t.end());
    // and they will be compared, if they are equal, then they are anagrams
    return s == t;
}

TEST(PROBLEM_242, Example1) {
    std::string s("anagram");
    std::string t("nagaram");
    ASSERT_TRUE(isAnagram(s, t));
}

TEST(PROBLEM_242, Example2) {
    std::string s("rat");
    std::string t("car");
    ASSERT_FALSE(isAnagram(s, t));
}
