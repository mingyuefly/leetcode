//
//  main.cpp
//  insert_into_a_Binary_Search_Tree
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) {
            return new TreeNode(val);
        }
        if (val < root->val) {
            root->left = insertIntoBST(root->left, val);
        } else if (val > root->val) {
            root->right = insertIntoBST(root->right, val);
        } else {
            return root;
        }
        return root;
    }
};

class Solution1 {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) {
            return new TreeNode(val);
        }
        TreeNode * tmpN = root;
        TreeNode * tmpNParent = nullptr;
        while (tmpN != nullptr) {
            tmpNParent = tmpN;
            if (val < tmpN->val) {
                tmpN = tmpN->left;
            } else if (val > tmpN->val) {
                tmpN = tmpN->right;
            } else {
                return root;
            }
        }
        if (val < tmpNParent->val) {
            tmpNParent->left = new TreeNode(val);
        } else {
            tmpNParent->right = new TreeNode(val);
        }
        
        return root;
    }
};

class Solution2 {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) {
            return new TreeNode(val);
        }
        TreeNode* pos = root;
        while (pos != nullptr) {
            if (val < pos->val) {
                if (pos->left == nullptr) {
                    pos->left = new TreeNode(val);
                    break;
                } else {
                    pos = pos->left;
                }
            } else {
                if (pos->right == nullptr) {
                    pos->right = new TreeNode(val);
                    break;
                } else {
                    pos = pos->right;
                }
            }
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
    
    TreeNode *root = new TreeNode(4);
    TreeNode *root1 = new TreeNode(2);
    TreeNode *root2 = new TreeNode(7);
    TreeNode *root3 = new TreeNode(1);
    TreeNode *root4 = new TreeNode(3);
    
    root->left = root1;
    root->right = root2;
    root1->left = root3;
    root1->right = root4;
    
    show(root);
    cout << endl;
    
    //    Solution solution;
    //    solution.insertIntoBST(root, 5);
    //    show(root);
    //    cout << endl;
    
    //    Solution solution;
    //    solution.insertIntoBST(root, 5);
    //    show(root);
    //    cout << endl;
    
    
    Solution2 solution;
    solution.insertIntoBST(root, 5);
    show(root);
    cout << endl;
    
    
    return 0;
}
