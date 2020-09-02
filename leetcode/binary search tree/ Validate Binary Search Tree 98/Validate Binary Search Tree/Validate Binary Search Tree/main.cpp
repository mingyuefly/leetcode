//
//  main.cpp
//  Validate Binary Search Tree
//
/**
 Given a binary tree, determine if it is a valid binary search tree (BST).

 Assume a BST is defined as follows:

 The left subtree of a node contains only nodes with keys less than the node's key.
 The right subtree of a node contains only nodes with keys greater than the node's key.
 Both the left and right subtrees must also be binary search trees.
  

 Example 1:

     2
    / \
   1   3

 Input: [2,1,3]
 Output: true
 Example 2:

     5
    / \
   1   4
      / \
     3   6

 Input: [5,1,4,null,null,3,6]
 Output: false
 Explanation: The root node's value is 5 but its right child's value is 4.
 */
//  Created by mingyue on 2020/9/2.
//  Copyright © 2020 Gmingyue. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {
        
    }
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
        
    }
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {
        
    }
};

using namespace std;

class Solution {
public:
    vector<int> nodes;
    bool isValidBST(TreeNode* root) {
        if (!root) {
            return true;
        }
        inorder(root);
        vector<int> nodes1 = nodes;
        set<int> nodeSet;
        for (int i = 0; i < nodes.size(); i++) {
            nodeSet.insert(nodes[i]);
        }
        if (nodeSet.size() != nodes.size()) {
            return false;
        }
        sort(nodes1.begin(), nodes1.end());
        return nodes == nodes1;
    }
    void inorder(TreeNode *root) {
        if (!root) {
            return;
        }
        inorder(root->left);
        nodes.push_back(root->val);
        inorder(root->right);
    }
};

int main(int argc, const char * argv[]) {
    /*
    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = 2;
    struct TreeNode *root1 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root1->val = 1;
    struct TreeNode *root2 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root2->val = 3;
    root->left = root1;
    root->right = root2;
    root1->left = nullptr;
    root1->right = nullptr;
    root2->left = nullptr;
    root2->right = nullptr;
     */
    
    /*
    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = 5;
    struct TreeNode *root1 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root1->val = 1;
    struct TreeNode *root2 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root2->val = 4;
    struct TreeNode *root3 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root1->val = 3;
    struct TreeNode *root4 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root2->val = 6;
    root->left = root1;
    root->right = root2;
    root1->left = nullptr;
    root1->right = nullptr;
    root2->left = root3;
    root2->right = root4;
    root3->left = nullptr;
    root3->right = nullptr;
    root4->left = nullptr;
    root4->right = nullptr;
     */
    
    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = 1;
    struct TreeNode *root1 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root1->val = 1;
    root->left = root1;
    root->right = nullptr;
    root1->left = nullptr;
    root1->right = nullptr;
    
    Solution solution = Solution();
    bool isValidBST = solution.isValidBST(root);
    if (isValidBST) {
        cout << "valid" << endl;
    } else {
        cout << "invalid" << endl;
    }
    
    return 0;
}
