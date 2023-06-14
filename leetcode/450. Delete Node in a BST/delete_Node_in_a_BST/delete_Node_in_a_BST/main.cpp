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

class Solution1 {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode * cur = root, * curParent = nullptr;
        while (cur && cur->val != key) {
            curParent = cur;
            if (key < cur->val) {
                cur = cur->left;
            } else {
                cur = cur->right;
            }
        }
        if (cur == nullptr) {
            // 要删除的值不存在
            return root;
        }
        if (!cur->left && !cur->right) {
            // 要删除的节点没有子树
            cur = nullptr;
        } else if (!cur->right) {
            // 要删除的节点没有右子树
            cur = cur->left;
        } else if (!cur->left) {
            // 要删除的节点没有左子树
            cur = cur->right;
        } else {
            // 要删除的节点有左右子树
            TreeNode * minRight = cur->right;
            TreeNode * minRightParent = cur;
            while (minRight->left) {
                minRightParent = minRight;
                minRight = minRight->left;
            }
            if (minRightParent->val == cur->val) {
                // 要删除的节点的右节点没有左子树
                minRightParent->right = minRight->right;
            } else {
                // 删除要继承的子节点，并将要继承的子节点的子树合并
                minRightParent->left = minRight->right;
            }
            // 将要删除的子节点的左右子树赋给要继承的子节点
            minRight->right = cur->right;
            minRight->left = cur->left;
            // 保存要继承的节点
            cur = minRight;
        }
        
        if (!curParent) {
            // 要删除的是根节点
            return cur;
        } else {
            if (curParent->left && curParent->left->val == key) {
                curParent->left = cur;
            } else {
                curParent->right = cur;
            }
            return root;
        }
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
    
//    Solution solution;
//    TreeNode * rootD = solution.deleteNode(root, 3);
//    show(rootD);
    
//    Solution solution;
//    TreeNode * rootD = solution.deleteNode(root, 5);
//    show(rootD);
    
//    Solution1 solution;
//    TreeNode * rootD = solution.deleteNode(root, 3);
//    show(rootD);
    
    Solution1 solution;
    TreeNode * rootD = solution.deleteNode(root, 5);
    show(rootD);
    
//    show(root);
    cout << endl;
    
    delete root;
    delete root1;
    delete root2;
    delete root3;
    delete root4;
    delete root5;
    
    return 0;
}
