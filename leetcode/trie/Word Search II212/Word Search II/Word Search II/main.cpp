//
//  main.cpp
//  Word Search II
//
/**
 Given a 2D board and a list of words from the dictionary, find all words in the board.

 Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

  

 Example:

 Input:
 board = [
   ['o','a','a','n'],
   ['e','t','a','e'],
   ['i','h','k','r'],
   ['i','f','l','v']
 ]
 words = ["oath","pea","eat","rain"]

 Output: ["eat","oath"]
  

 Note:

 All inputs are consist of lowercase letters a-z.
 The values of words are distinct.
 */
//  Created by mingyue on 2020/10/10.
//  Copyright © 2020 Gmingyue. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
//#include <set>
//#include <hashmap>

using namespace std;

// 根据具体情况优化trie树很重要
class Trie {
public:
    string word = "";
    bool isWord = false;
    vector<Trie *> tries;
    
    Trie() {
        tries.reserve(26);
        for (int i = 0; i < 26; i++) {
            tries[i] = nullptr;
        }
    }
    
    void insert(string word) {
        Trie *trie = this;
        for (char a:word) {
            int index = a - 'a';
            auto& tmpTrie = trie->tries[index];
            if (tmpTrie == nullptr) {
                Trie* new_trie = new Trie();
                tmpTrie = new_trie;
            }
            trie = tmpTrie;
        }
        trie->isWord = true;
        trie->word = word;
    }
};

class Solution {
public:
    void dfs(int x, int y, Trie *trie, vector<vector<char>>& board, vector<string> *result) {
        if (x >= board.size() || y >= board[x].size() || x < 0 || y < 0) {
            return;
        }
        char c = board[x][y];
        if (c == '.') {
            return;
        }
        Trie *next_trie = trie->tries[c - 'a'];
        if (next_trie == nullptr) {
            return;
        }
        board[x][y] = '.';
        if (next_trie->isWord) {
            result->push_back(next_trie->word);
            next_trie->isWord = false;
        }
        dfs(x + 1, y, next_trie, board, result);
        dfs(x, y + 1, next_trie, board, result);
        dfs(x - 1, y, next_trie, board, result);
        dfs(x, y - 1, next_trie, board, result);
        board[x][y] = c;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if (board.empty()) {
            return {};
        }
        Trie *trie = new Trie();
        vector<string> result;
        for (string word:words) {
            trie->insert(word);
        }
        int row = (int)board.size();
        int column = (int)board[0].size();
        vector<vector<bool>> visited(row, vector<bool>(column, false));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                dfs(i, j, trie, board, &result);
            }
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    
    vector<vector<char>> board = {
        {'o','a','a','n'},
        {'e','t','a','e'},
        {'i','h','k','r'},
        {'i','f','l','v'}
    };
    vector<string> words = {"oath","pea","eat","rain"};
    
    /*
    vector<vector<char>> board = {
        {'a','a'}
    };
    vector<string> words = {"a"};
     */
    /*
    vector<vector<char>> board = {
        {'b','b','a','a','b','a'},
        {'b','b','a','b','a','a'},
        {'b','b','b','b','b','b'},
        {'a','a','a','b','b','a'},
        {'a','b','a','a','b','b'}
    };
    vector<string> words = {"abbbababaa"};
     */
    Solution solution = Solution();
    vector<string> result = solution.findWords(board, words);
    for(string str:result) {
        cout << str << endl;
    }
    //cout << endl;
    return 0;
}
