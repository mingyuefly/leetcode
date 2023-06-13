//
//  main.cpp
//  Binary Tree Level Order Traversal
//
/**
 Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

 For example:
 Given binary tree [3,9,20,null,null,15,7],
     3
    / \
   9  20
     /  \
    15   7
 return its level order traversal as:
 [
   [3],
   [9,20],
   [15,7]
 ]

 */
//  Created by mingyue on 2020/9/20.
//  Copyright © 2020 Gmingyue. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;
        if (!root) {
            return v;
        }
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> v1;
            long size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode *node = q.front();
                q.pop();
                v1.push_back(node->val);
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            v.push_back(v1);
        }
        return v;
    }
};

class Solution1 {
    void dfs(TreeNode* root, vector<vector<int>> &v, int level) {
        if (!root) {
            return;
        }
        if (level >= v.size()) {
            v.push_back(vector<int>());
        }
        v[level].push_back(root->val);
        dfs(root->left, v, level + 1);
        dfs(root->right, v, level + 1);
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;
        if (!root) {
            return v;
        }
        dfs(root, v, 0);
        return v;
    }
};

int main(int argc, const char * argv[]) {
    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = 3;
    struct TreeNode *node1 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node1->val = 9;
    struct TreeNode *node2 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node2->val = 20;
    struct TreeNode *node3 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node3->val = 15;
    struct TreeNode *node4 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node4->val = 7;
    root->left = node1;
    root->right = node2;
    node1->left = nullptr;
    node1->right = nullptr;
    node2->left = node3;
    node2->right = node4;
    node3->left = nullptr;
    node3->right = nullptr;
    node4->left = nullptr;
    node4->right = nullptr;
    
//    Solution solution = Solution();
//    vector<vector<int>> v = solution.levelOrder(root);
    
    Solution1 solution = Solution1();
    vector<vector<int>> v = solution.levelOrder(root);
    
    for (int i = 0; i < v.size(); i++) {
        vector<int> v1 = v[i];
        for (int j = 0; j < v1.size(); j++) {
            cout << v1[j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    
    free(root);
    free(node1);
    free(node2);
    free(node3);
    free(node4);
    
    return 0;
}
