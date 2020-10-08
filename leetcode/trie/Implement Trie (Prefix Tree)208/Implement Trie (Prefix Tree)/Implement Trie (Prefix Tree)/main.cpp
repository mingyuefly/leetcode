//
//  main.cpp
//  Implement Trie (Prefix Tree)
//
//  Created by mingyue on 2020/10/8.
//  Copyright © 2020 Gmingyue. All rights reserved.
//

#include <iostream>
#include <string>
#include <array>

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

int main(int argc, const char * argv[]) {
    Trie trie = Trie();

    trie.insert("apple");
    cout << trie.search("apple") << endl;
    cout << trie.search("app") << endl;
    cout << trie.startsWith("app") << endl;
    trie.insert("app");
    cout << trie.search("app") << endl;
    return 0;
}
