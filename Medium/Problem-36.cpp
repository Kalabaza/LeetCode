#include <gtest/gtest.h>

#include <set>
#include <vector>

bool isValidSubBox(std::vector<std::vector<char>>& board, int X, int Y) {
    std::set<char> digits;
    for(int x = 0; x < 3; ++x) {
        for(int y = 0; y < 3; ++y) {
            // ignore the dots in the board
            if(board[X + x][Y + y] == '.')
                continue;
            // check if the digit is already present in the set, that means
            // it was already found in the sub-box
            if(digits.count(board[X + x][Y + y]))
                return false;
            // if the digit was not found, then add it to the set and continue
            digits.insert(board[X + x][Y + y]);
        }
    }
    return true;
}

/**
 * Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
 *
 * 1- Each row must contain the digits 1-9 without repetition.
 * 2- Each column must contain the digits 1-9 without repetition.
 * 3- Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.
 */
bool isValidSudoku(std::vector<std::vector<char>>& board) {
    // first check that the 9 sub-boxes contained in the board are valid
    for(int x = 0; x < 3; ++x) {
        for(int y = 0; y < 3; ++y) {
            // if a sub-box is not valid, then return from here to avoid any more validations
            if(!isValidSubBox(board, x * 3, y * 3))
                return false;
        }
    }

    // Now validate all the rows to check that they are valid
    for(int x = 0; x < 9; ++x) {
        std::set<char> digits;
        for(int y = 0; y < 9; ++y) {
            // ignore the dots in the board
            if(board[x][y] == '.')
                continue;
            // if the digit is already in the set, return since there is a
            // duplicated digit
            if(digits.count(board[x][y]))
                return false;
            // otherwise add the digit to the set
            digits.insert(board[x][y]);
        }
    }

    // Finally validate all the columns to see that they are also valid
    for(int y = 0; y < 9; ++y) {
        std::set<char> digits;
        for(int x = 0; x < 9; ++x) {
            // ignore the dots in the board
            if(board[x][y] == '.')
                continue;
            // if the digit is already in the set, return since there is a
            // duplicated digit
            if(digits.count(board[x][y]))
                return false;
            // otherwise add the digit to the set
            digits.insert(board[x][y]);
        }
    }

    // if this point is reached, it means all the validations were successful
    return true;
}

TEST(PROBLEM_36, Example1) {
    std::vector<std::vector<char>> board{
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    ASSERT_TRUE(isValidSudoku(board));
}

TEST(PROBLEM_36, Example2) {
    std::vector<std::vector<char>> board{
        {'8','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    ASSERT_FALSE(isValidSudoku(board));
}
