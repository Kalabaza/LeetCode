#include <gtest/gtest.h>

/**
 * Given a string 's', return the longest palindromic substring in 's'.
 */

std::string longestPalindrome(const std::string& s) {
   std::string longest;
   // Going from the first position to the last in the string
   for(int32_t index = 0; index < static_cast<int32_t>(s.size()); ++index) {
      // An offset is used to deal with palindromes of odd and even length
      for(uint32_t offset = 0; offset < 2; ++offset) {
         // A left and right pointers will be used to check the characters of
         // the new substring, to see if that is a palindrome
         int32_t left = index, right = index + offset;
         while(left >= 0 && right < static_cast<int32_t>(s.size()) &&
               s[left] == s[right]) {
            const int32_t size = right - left + 1;
            // Check if a new substring was found
            if(size > static_cast<int32_t>(longest.size())) {
               longest = s.substr(left, size);
            }
            --left;
            ++right;
         }
      }
   }
   return longest;
}

TEST(PROBLEM_5, Example_1) {
   const std::string input("babad");
   const std::string output("bab");
   ASSERT_EQ(output, longestPalindrome(input));
}

TEST(PROBLEM_5, Example_2) {
   const std::string input("cbbd");
   const std::string output("bb");
   ASSERT_EQ(output, longestPalindrome(input));
}
