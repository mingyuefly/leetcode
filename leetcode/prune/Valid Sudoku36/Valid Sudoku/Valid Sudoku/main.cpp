//
//  main.cpp
//  Valid Sudoku
//
/**
 Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

 Each row must contain the digits 1-9 without repetition.
 Each column must contain the digits 1-9 without repetition.
 Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
 Note:

 A Sudoku board (partially filled) could be valid but is not necessarily solvable.
 Only the filled cells need to be validated according to the mentioned rules.
  

 Example 1:


 Input: board =
 [["5","3",".",".","7",".",".",".","."]
 ,["6",".",".","1","9","5",".",".","."]
 ,[".","9","8",".",".",".",".","6","."]
 ,["8",".",".",".","6",".",".",".","3"]
 ,["4",".",".","8",".","3",".",".","1"]
 ,["7",".",".",".","2",".",".",".","6"]
 ,[".","6",".",".",".",".","2","8","."]
 ,[".",".",".","4","1","9",".",".","5"]
 ,[".",".",".",".","8",".",".","7","9"]]
 Output: true
 Example 2:

 Input: board =
 [["8","3",".",".","7",".",".",".","."]
 ,["6",".",".","1","9","5",".",".","."]
 ,[".","9","8",".",".",".",".","6","."]
 ,["8",".",".",".","6",".",".",".","3"]
 ,["4",".",".","8",".","3",".",".","1"]
 ,["7",".",".",".","2",".",".",".","6"]
 ,[".","6",".",".",".",".","2","8","."]
 ,[".",".",".","4","1","9",".",".","5"]
 ,[".",".",".",".","8",".",".","7","9"]]
 Output: false
 Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
 Constraints:

 board.length == 9
 board[i].length == 9
 board[i][j] is a digit or '.'.

 */
//  Created by mingyue on 2020/10/7.
//  Copyright © 2020 Gmingyue. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        char cs[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
        set<char> charSet(cs, cs + 9);
        int length = (int)board.size();
        for (int i = 0; i < length; i++) {
            vector<char> rowV = board[i];
            set<char> rowSet;
            set<char> volumnSet;
            set<char> boxSet;
            for (int j = 0; j < length; j++) {
                // check row
                char a = rowV[j];
                if (charSet.count(a) == 0) {
                    continue;
                }
                if (rowSet.count(a) == 0) {
                    rowSet.insert(a);
                } else {
                    return false;
                }
                if (j == length - 1) {
                    rowSet.clear();
                }
            }
            
            for (int j = 0; j < length; j++) {
                // check volumn
                char b = board[j][i];
                if (charSet.count(b) == 0) {
                    continue;
                }
                if (volumnSet.count(b) == 0) {
                    volumnSet.insert(b);
                } else {
                    return false;
                }
                if (j == length - 1) {
                    volumnSet.clear();
                }
            }
            
            for (int j = 0; j < length; j++) {
                // check box
                char c = board[j / 3 + (i / 3) * 3][j % 3 + (i % 3) * 3];
                if (charSet.count(c) == 0) {
                    continue;
                }
                if (boxSet.count(c) == 0) {
                    boxSet.insert(c);
                } else {
                    return false;
                }
                if (j == length - 1) {
                    boxSet.clear();
                }
            }
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    
    char boardArray[9][9] = {{'8','3', '.','.','7','.','.','.','.'}
    ,{'6','.', '.','1','9','5','.','.','.'}
    ,{'.','9', '8','.','.','.','.','6','.'}
    ,{'8','.', '.','.','6','.','.','.','3'}
    ,{'4','.', '.','8','.','3','.','.','1'}
    ,{'7','.', '.','.','2','.','.','.','6'}
    ,{'.','6', '.','.','.','.','2','8','.'}
    ,{'.','.', '.','4','1','9','.','.','5'}
    ,{'.','.', '.','.','8','.','.','7','9'}};
    
    /*
    char boardArray[9][9] = {{'5','3', '.','.','7','.','.','.','.'}
    ,{'6','.', '.','1','9','5','.','.','.'}
    ,{'.','9', '8','.','.','.','.','6','.'}
    ,{'8','.', '.','.','6','.','.','.','3'}
    ,{'4','.', '.','8','.','3','.','.','1'}
    ,{'7','.', '.','.','2','.','.','.','6'}
    ,{'.','6', '.','.','.','.','2','8','.'}
    ,{'.','.', '.','4','1','9','.','.','5'}
    ,{'.','.', '.','.','8','.','.','7','9'}};
     */
    
    vector<vector<char>> inputV;
    for (int i = 0; i < 9; i++) {
        vector<char> row;
        for (int j = 0; j < 9; j++) {
            row.push_back(boardArray[i][j]);
        }
        inputV.push_back(row);
    }
    
    Solution solution = Solution();
    cout << solution.isValidSudoku(inputV) << endl;
    
    /*
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << inputV[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
     */
    
    
    
    return 0;
}
