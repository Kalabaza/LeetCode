#include <gtest/gtest.h>

#include <set>

/**
 * Given a string 's', find the length of the longest substring without repeating characters.
 */

int32_t lengthOfLongestSubstring(const std::string& s) {
   // A set will be used to save the characters of the string that will compose the substring.
   // Since no repeated characters are allowed, the set saves the characters until a repeated one is found
   std::set<char> letters;
   std::size_t longest = 0;
   std::size_t prevStart = 0;
   for(uint32_t index = 0; index < s.length(); ++index) {
      // Once a repeated character is found, remove the characters until this repeated character was found
      if(0 != letters.count(s[index])) {
         longest = std::max(longest, letters.size());
         while(s[prevStart] != s[index]) {
            letters.erase(s[prevStart++]);
         }
         // move the prevStart to the next position, after the repeated character
         ++prevStart;
      } else {
         // if no repeated character was found, add the current character to the set
         letters.insert(s[index]);
      }
   }
   // check if there are still characters in the set or return the longest value found
   return static_cast<int32_t>(std::max(longest, (letters.size())));
}

TEST(PROBLEM_3, Example_1) {
   const std::string input("abcabcbb");
   constexpr int32_t output = 3;
   ASSERT_EQ(output, lengthOfLongestSubstring(input));
}

TEST(PROBLEM_3, Example_2) {
   const std::string input("bbbbb");
   constexpr int32_t output = 1;
   ASSERT_EQ(output, lengthOfLongestSubstring(input));
}

TEST(PROBLEM_3, Example_3) {
   const std::string input("pwwkew");
   constexpr int32_t output = 3;
   ASSERT_EQ(output, lengthOfLongestSubstring(input));
}
