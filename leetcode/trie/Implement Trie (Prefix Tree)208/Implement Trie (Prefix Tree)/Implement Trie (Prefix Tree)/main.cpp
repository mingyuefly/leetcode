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

class TrieNode {
public:
    char val;
    bool isWord;
    array<TrieNode *, 26> nodes;
    TrieNode(){};
    TrieNode(char c) {
        TrieNode node = TrieNode();
        node.val = c;
    }
};

class Trie {
    public:
    TrieNode rootNode;
    /** Initialize your data structure here. */
    Trie() {
        rootNode = TrieNode();
        rootNode.val = ' ';
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *node = &rootNode;
        for (int i = 0; i < word.length(); i++) {
            TrieNode *tmpNode = node->nodes[word[i] - 'a'];
            if (tmpNode == nullptr) {
                tmpNode = new TrieNode(word[i]);
                node->nodes[word[i] - 'a'] = tmpNode;
            }
            node = tmpNode;
        }
        node->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *node = &rootNode;
        for (int i = 0; i < word.length(); i++) {
            TrieNode *tmpNode = node->nodes[word[i] - 'a'];
            if (tmpNode == nullptr) {
                return false;
            }
            node = tmpNode;
        }
        return node->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *node = &rootNode;
        for (int i = 0; i < prefix.length(); i++) {
            TrieNode *tmpNode = node->nodes[prefix[i] - 'a'];
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
