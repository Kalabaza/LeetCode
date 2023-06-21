#include <gtest/gtest.h>

#include <map>
#include <queue>
#include <string>

/**
 * Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 *
 * An input string is valid if:
 *
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 * Every close bracket has a corresponding open bracket of the same type.
 */

bool isValid(std::string s) {
    // Hold the characters in a queue, so always push at the top and also take
    // the newest element from the top.
    std::queue<char> characters;
    // This map is used to know which closing character is expected for each
    // opening bracket.
    std::map<char, char> closing{{'(',')'},{'{','}'},{'[',']'}};

    // Go over all the characters in the string.
    for(const auto& c : s) {
        switch(c) {
            case '(':
            case '{':
            case '[': {
                characters.push(c);
                break;
            }
            case ')':
            case '}':
            case ']': {
                auto top = characters.front();
                characters.pop();
                // If the closing character is not the expected one, then this
                // is not a valid string.
                if (closing[top] != c)
                    return false;
                break;
            }
            default:
                return false;
        }
    }

    // If there was not a mistake, then the queue muss be empty to have a valid
    // string.
    return characters.empty();
}

TEST(PROBLEM_20, Example1) {
    std::string s = "()";
    ASSERT_TRUE(isValid(s));
}

TEST(PROBLEM_20, Example2) {
    std::string s = "()[]{}";
    ASSERT_TRUE(isValid(s));
}

TEST(PROBLEM_20, Example3) {
    std::string s = "(]";
    ASSERT_FALSE(isValid(s));
}