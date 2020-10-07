//
//  main.cpp
//  Sudoku Solver
//
/**
 Write a program to solve a Sudoku puzzle by filling the empty cells.

 A sudoku solution must satisfy all of the following rules:

 Each of the digits 1-9 must occur exactly once in each row.
 Each of the digits 1-9 must occur exactly once in each column.
 Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
 The '.' character indicates empty cells.

  

 Example 1:


 Input: board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
 Output: [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
 Explanation: The input board is shown above and the only valid solution is shown below:


  

 Constraints:

 board.length == 9
 board[i].length == 9
 board[i][j] is a digit or '.'.
 It is guaranteed that the input board has only one solution.
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
    int spaceSum;
    vector<vector<int>> spaceV;
    bool sign;
    bool isValidSudoku(int n, char c, vector<vector<char>>& board) {
        vector<int> spacePoint = spaceV[n];
        int length = (int)board.size();
        for (int i = 0; i < length; i++) {
            if (board[spacePoint[0]][i] == c) {
                return false;
            }
        }
        for (int i = 0; i < length; i++) {
            if (board[i][spacePoint[1]] == c) {
                return false;
            }
        }
        int row = (spacePoint[0] / 3) * 3;
        int column = (spacePoint[1] / 3) * 3;
        for (int i = row; i < row + 3; i++) {
            for (int j = column; j < column + 3; j++) {
                if (board[i][j] == c) {
                    return false;
                }
            }
        }
        return true;
    }
    void dfs(int n, vector<vector<char>>& board) {
        if (n == spaceSum) {
            sign = true;
            return;
        }
        char cs[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
        vector<int> spacePoint = spaceV[n];
        for (int j = 0; j < 9; j++) {
            if (isValidSudoku(n, cs[j], board)) {
                board[spacePoint[0]][spacePoint[1]] = cs[j];
                dfs(n + 1, board);
                if (sign) {
                    return ;
                }
                board[spacePoint[0]][spacePoint[1]] = '.';
            }
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        int sum = 0;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == '.') {
                    vector<int> a;
                    a.push_back(i);
                    a.push_back(j);
                    spaceV.push_back(a);
                    sum++;
                }
            }
        }
        spaceSum = sum;
        sign = false;
        dfs(0, board);
    }
};

int main(int argc, const char * argv[]) {
    char boardArray[9][9] = {{'5','3', '.','.','7','.','.','.','.'}
    ,{'6','.', '.','1','9','5','.','.','.'}
    ,{'.','9', '8','.','.','.','.','6','.'}
    ,{'8','.', '.','.','6','.','.','.','3'}
    ,{'4','.', '.','8','.','3','.','.','1'}
    ,{'7','.', '.','.','2','.','.','.','6'}
    ,{'.','6', '.','.','.','.','2','8','.'}
    ,{'.','.', '.','4','1','9','.','.','5'}
    ,{'.','.', '.','.','8','.','.','7','9'}};
    
    vector<vector<char>> inputV;
    for (int i = 0; i < 9; i++) {
        vector<char> row;
        for (int j = 0; j < 9; j++) {
            row.push_back(boardArray[i][j]);
        }
        inputV.push_back(row);
    }
    
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << inputV[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
    
    Solution solution = Solution();
    solution.solveSudoku(inputV);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << inputV[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
    
    return 0;
}
