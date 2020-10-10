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
#include <set>

using namespace std;

struct TrieNode {
    bool word = false;
    TrieNode *nodes[26] = {nullptr};
};

class Trie {
public:
    TrieNode *rootNode;
    /** Initialize your data structure here. */
    Trie() {
        rootNode = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *node = rootNode;
        for (char a:word) {
            int index = a - 'a';
            TrieNode *tmpNode = node->nodes[index];
            if (tmpNode == nullptr) {
                tmpNode = new TrieNode();
                node->nodes[index] = tmpNode;
            }
            node = tmpNode;
        }
        node->word = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *node = rootNode;
        for (char a:word) {
            int index = a - 'a';
            TrieNode *tmpNode = node->nodes[index];
            if (tmpNode == nullptr) {
                return false;
            }
            node = tmpNode;
        }
        return node->word;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *node = rootNode;
        for (char a:prefix) {
            int index = a - 'a';
            TrieNode *tmpNode = node->nodes[index];
            if (tmpNode == nullptr) {
                return false;
            }
            node = tmpNode;
        }
        return true;;
    }
};

class Solution {
public:
    Trie trie;
    vector<string> result;
    set<string> rs;
    void dfs(vector<vector<char>>& board, int x, int y, string str, vector<vector<bool>> visited) {
        if (x >= board.size() || y >= board[0].size() || x < 0 || y < 0) {
            return;
        }
        if (visited[x][y]) {
            return;
        }
        str += board[x][y];
        if (!trie.startsWith(str)) {
            return;
        }
        if (trie.search(str)) {
            if (rs.count(str) == 0) {
                result.push_back(str);
                rs.insert(str);
            }
        }
        visited[x][y] = true;
        dfs(board, x + 1, y, str, visited);
        dfs(board, x - 1, y, str, visited);
        dfs(board, x, y + 1, str, visited);
        dfs(board, x, y - 1, str, visited);
        visited[x][y] = false;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        trie = Trie();
        for (string word:words) {
            trie.insert(word);
        }
        int row = (int)board.size();
        int column = (int)board[0].size();
        vector<vector<bool>> visited(row, vector<bool>(column, false));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                dfs(board, i, j, "", visited);
            }
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    /*
    vector<vector<char>> board = {
        {'o','a','a','n'},
        {'e','t','a','e'},
        {'i','h','k','r'},
        {'i','f','l','v'}
    };
    vector<string> words = {"oath","pea","eat","rain"};
     */
    /*
    vector<vector<char>> board = {
        {'a','a'}
    };
    vector<string> words = {"a"};
     */
    vector<vector<char>> board = {
        {'b','b','a','a','b','a'},
        {'b','b','a','b','a','a'},
        {'b','b','b','b','b','b'},
        {'a','a','a','b','b','a'},
        {'a','b','a','a','b','b'}
    };
    vector<string> words = {"abbbababaa"};
    Solution solution = Solution();
    vector<string> result = solution.findWords(board, words);
    for(string str:result) {
        cout << str << endl;
    }
    //cout << endl;
    return 0;
}
