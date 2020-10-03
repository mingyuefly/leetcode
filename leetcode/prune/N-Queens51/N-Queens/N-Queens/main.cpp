//
//  main.cpp
//  N-Queens
//
/**
 The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.



 Given an integer n, return all distinct solutions to the n-queens puzzle.

 Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

 Example:

 Input: 4
 Output: [
  [".Q..",  // Solution 1
   "...Q",
   "Q...",
   "..Q."],

  ["..Q.",  // Solution 2
   "Q...",
   "...Q",
   ".Q.."]
 ]
 Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above.
 */
//  Created by mingyue on 2020/10/3.
//  Copyright © 2020 Gmingyue. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isSafe(vector<string> &v, int row, int column, int n) {
        int i, x, y;
        for (i = 0; i < row; i++) {
            if (v[i][column] == 'Q') {
                return false;
            }
        }
        x = row - 1;
        y = column - 1;
        while (x >= 0 && y >= 0) {
            if (v[x][y] == 'Q') {
                return false;
            }
            x--;
            y--;
        }
        x = row - 1;
        y = column + 1;
        while (x >= 0 && y < n) {
            if (v[x][y] == 'Q') {
                return false;
            }
            x--;
            y++;
        }
        return true;
    }
    bool placeQueen(vector<vector<string>> &sol, int row, int &n, vector<string> &v) {
        if (row == n) {
            sol.push_back(v);
            return false;
        }
        for (int column = 0; column < n; column++) {
            if (isSafe(v, row, column, n)) {
                v[row][column] = 'Q';
                if (placeQueen(sol, row + 1, n, v)) {
                    return true;
                }
            }
            v[row][column] = '.';
        }
        return false;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> sol;
        string s;
        for (int i = 0; i < n; i++) {
            s += ".";
        }
        vector<string> v(n, s);
        placeQueen(sol, 0, n, v);
        return sol;
    }
};

int main(int argc, const char * argv[]) {
    
    Solution solution = Solution();
    int n = 4;
    vector<vector<string>> sol = solution.solveNQueens(n);
    for (int i = 0; i < sol.size(); i++) {
        vector<string> v = sol[i];
        for (int j = 0; j < v.size(); j++) {
            cout << v[j] << endl;
        }
        cout << endl;
    }
    
    return 0;
}
