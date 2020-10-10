//
//  main.cpp
//  Word Search
//
//  Created by mingyue on 2020/10/10.
//  Copyright © 2020 Gmingyue. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    const vector<vector<int>> dirs {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    bool dfs(int x, int y, int index, vector<vector<char>>& board, string &word) {
        if (index == word.size()) {
            return true;
        }
        
        if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size() || board[x][y] != word[index]) {
            return false;
        }
        
        char old = board[x][y];
        board[x][y] = '$';
        
        // all branches
        for (const auto& dir : dirs) {
            if (dfs(x + dir[0], y + dir[1], index + 1, board, word)) {
                board[x][y] = old;
                return true;
            }
        }
        
        board[x][y] = old;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty()) {
            return {};
        }
        
        int row = (int)board.size();
        int column = (int)board[0].size();
        vector<vector<bool>> visited(row, vector<bool>(column, false));
        bool exist = false;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                if (word[0] == board[i][j]) {
                    exist = dfs(i, j, 0, board, word);
                    if (exist) {
                        return exist;
                    }
                }
            }
        }
        return exist;
    }
};

int main(int argc, const char * argv[]) {
    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    string word = "ABCCED";
    Solution solution = Solution();
    cout << solution.exist(board, word) << endl;
    return 0;
}
