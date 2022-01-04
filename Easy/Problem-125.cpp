#include <gtest/gtest.h>

#include <algorithm>
#include <string>

/**
 * Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
 */
bool isPalindrome(std::string s) {
    // first remove the punctuation symbols
    s.erase(std::remove_if(s.begin(), s.end(), ::ispunct), s.end());
    // then the spaces
    s.erase(std::remove_if(s.begin(), s.end(), ::isspace), s.end());
    // and finaly make everything lowercase
    std::transform(s.begin(), s.end(), s.begin(), ::tolower);
    // NOTE: since the empty string is a valid palindrome, an special validation has to be used
    if(s.size() == 0)
        return true;
    // now compare from the beggining to the end to see if the characters are the same
    for(uint i = 0, j = s.size() - 1; i < j; ++i, --j)
        if(s[i] != s[j])
            return false;
    return true;
}

TEST(PROBLEM_125, Example1) {
    std::string input("A man, a plan, a canal: Panama");
    ASSERT_TRUE(isPalindrome(input));
}

TEST(PROBLEM_125, Example2) {
    std::string input("race a car");
    ASSERT_FALSE(isPalindrome(input));
}

TEST(PROBLEM_125, Example3) {
    std::string input("");
    ASSERT_TRUE(isPalindrome(input));
}

TEST(PROBLEM_125, Example4) {
    std::string input(" ");
    ASSERT_TRUE(isPalindrome(input));
}
