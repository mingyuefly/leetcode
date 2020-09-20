//
//  main.cpp
//  Maximum Depth of Binary Tree
//
/**
 Given a binary tree, find its maximum depth.

 The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

 Note: A leaf is a node with no children.

 Example:

 Given binary tree [3,9,20,null,null,15,7],

     3
    / \
   9  20
     /  \
    15   7
 return its depth = 3.
 */
//  Created by mingyue on 2020/9/20.
//  Copyright © 2020 Gmingyue. All rights reserved.
//

#include <iostream>
#include <algorithm>

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
    int maxDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
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
    
    Solution solution = Solution();
    int maxDepth = solution.maxDepth(root);
    cout << maxDepth << endl;
    
    free(root);
    free(node1);
    free(node2);
    free(node3);
    free(node4);
    
    return 0;
}
