//
//  main.cpp
//  Lowest Common Ancestor of a Binary Search Tree
//
/**
 Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

 According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

 Given binary search tree:  root = [6,2,8,0,4,7,9,null,null,3,5]

 Example 1:

 Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
 Output: 6
 Explanation: The LCA of nodes 2 and 8 is 6.
 Example 2:

 Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
 Output: 2
 Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.
  

 Constraints:

 All of the nodes' values will be unique.
 p and q are different and both values will exist in the BST.
 */
//  Created by mingyue on 2020/9/2.
//  Copyright © 2020 Gmingyue. All rights reserved.
//

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) {
            return root;
        }
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        if (!left) {
            return right;
        } else if (!right) {
            return left;
        } else {
            return root;
        }
    }
};

int main(int argc, const char * argv[]) {
    
    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = 6;
    struct TreeNode *node1 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node1->val = 2;
    struct TreeNode *node2 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node2->val = 8;
    struct TreeNode *node3 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node3->val = 0;
    struct TreeNode *node4 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node4->val = 4;
    struct TreeNode *node5 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node5->val = 7;
    struct TreeNode *node6 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node6->val = 9;
    struct TreeNode *node7 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node7->val = 3;
    struct TreeNode *node8 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node8->val = 5;
    root->left = node1;
    root->right = node2;
    node1->left = node3;
    node1->right = node4;
    node2->left = node5;
    node2->right = node6;
    node3->left = nullptr;
    node3->right = nullptr;
    node4->left = node7;
    node4->right = node8;
    node5->left = nullptr;
    node5->right = nullptr;
    node6->left = nullptr;
    node6->right = nullptr;
    node7->left = nullptr;
    node7->right = nullptr;
    node8->left = nullptr;
    node8->right = nullptr;
    
    Solution solution = Solution();
    //TreeNode *node = solution.lowestCommonAncestor(root, node4, node6);
    TreeNode *node = solution.lowestCommonAncestor(root, node3, node8);
    if (node) {
        cout << node->val << endl;
    } else {
        cout << "不存在" << endl;
    }
    
    return 0;
}
