//
//  main.cpp
//  delete_Node_in_a_BST
//
//  Created by gmy on 2023/6/14.
//

#include <iostream>

using namespace std;


//  Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {
        
    }
};


class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) {
            return nullptr;
        }
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            if (!root->left && !root->right) {
                return nullptr;
            }
            if (!root->right) {
                return root->left;
            }
            if (!root->left) {
                return root->right;
            }
            TreeNode * minN = root->right;
            while (minN->left) {
                minN = minN->left;
            }
            root->right = deleteNode(root->right, minN->val);
            minN->left = root->left;
            minN->right = root->right;
            root = minN;
        }
        return root;
    }
};

void show(TreeNode * root) {
    if (!root) {
        return;
    }
    show(root->left);
    cout << root->val << " ";
    show(root->right);
}

int main(int argc, const char * argv[]) {
//    TreeNode *root = new TreeNode(5);
//    TreeNode *root1 = new TreeNode(3);
//    TreeNode *root2 = new TreeNode(6);
//    TreeNode *root3 = new TreeNode(2);
//    TreeNode *root4 = new TreeNode(4);
//    TreeNode *root5 = new TreeNode(7);
//    root->left = root1;
//    root->right = root2;
//    root1->left = root3;
//    root1->right = root4;
//    root2->right = root5;
    
    TreeNode *root = new TreeNode(5);
    TreeNode *root1 = new TreeNode(3);
    TreeNode *root2 = new TreeNode(6);
    TreeNode *root3 = new TreeNode(2);
    TreeNode *root4 = new TreeNode(4);
    TreeNode *root5 = new TreeNode(7);
    root->left = root1;
    root->right = root2;
    root1->left = root3;
    root1->right = root4;
    root2->right = root5;
    
    show(root);
    cout << endl;
    
    Solution solution;
    solution.deleteNode(root, 3);
    
    show(root);
    cout << endl;
    
    delete root;
    delete root1;
    delete root2;
    delete root3;
    delete root4;
    delete root5;
    
    return 0;
}
