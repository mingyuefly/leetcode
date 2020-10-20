//
//  main.cpp
//  N-Queens II
//
/**
 The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.



 Given an integer n, return the number of distinct solutions to the n-queens puzzle.

 Example:

 Input: 4
 Output: 2
 Explanation: There are two distinct solutions to the 4-queens puzzle as shown below.
 [
  [".Q..",  // Solution 1
   "...Q",
   "Q...",
   "..Q."],

  ["..Q.",  // Solution 2
   "Q...",
   "...Q",
   ".Q.."]
 ]
 */
//  Created by mingyue on 2020/10/3.
//  Copyright © 2020 Gmingyue. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isSafe(vector<vector<int>> &board, int row, int column, int n) {
        int i, x, y;
        for (i = 0; i < row; i++) {
            if (board[i][column] == 1) {
                return false;
            }
        }
        x = row - 1;
        y = column - 1;
        while (x >= 0 && y >= 0) {
            if (board[x][y] == 1) {
                return false;
            }
            x--;
            y--;
        }
        x = row - 1;
        y = column + 1;
        while (x >= 0 && y < n) {
            if (board[x][y] == 1) {
                return false;
            }
            x--;
            y++;
        }
        return true;
    }
    void dfs(int &sol, int row, int &n, vector<vector<int>> &board) {
        if (row == n) {
            sol++;
            return;
        }
        for (int column = 0; column < n; column++) {
            if (isSafe(board, row, column, n)) {
                board[row][column] = 1;
                dfs(sol, row + 1, n, board);
                board[row][column] = 0;
            }
        }
    }
    int totalNQueens(int n) {
        int sol = 0;;
        vector<vector<int>> board(n, vector<int>(n, 0));
        dfs(sol, 0, n, board);
        return sol;
    }
};

class Solution1 {
public:
    int count = 0;
    void dfs(int n, int row, int col, int pie, int na) {
        if (row >= n) {
            count++;
            return;
        }
        int bits = (~(col | pie | na)) & ((1 << n) - 1);
        while (bits) {
            int p = bits & (-bits);
            dfs(n, row + 1, col | p, (pie | p) << 1, (na | p) >> 1);
            bits = bits & (bits - 1);
        }
    }
    int totalNQueens(int n) {
        if (n < 1) {
            return 0;
        }
        dfs(n, 0, 0, 0, 0);
        return count;
    }
};

int main(int argc, const char * argv[]) {
    
    Solution solution = Solution();
    //int n = 4;
    //cout << solution.totalNQueens(n) << endl;
    
    Solution1 solution1 = Solution1();
    int n = 4;
    cout << solution1.totalNQueens(n) << endl;
    
    return 0;
}
