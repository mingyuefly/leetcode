//
//  main.cpp
//  invert_Binary_Tree_cpp
//
/**
 Given the root of a binary tree, invert the tree, and return its root.
 
 
 
 Example 1:
 
 
 Input: root = [4,2,7,1,3,6,9]
 Output: [4,7,2,9,6,3,1]
 Example 2:
 
 
 Input: root = [2,1,3]
 Output: [2,3,1]
 Example 3:
 
 Input: root = []
 Output: []
 
 
 Constraints:
 
 The number of nodes in the tree is in the range [0, 100].
 -100 <= Node.val <= 100
 */
//  Created by gmy on 2023/6/9.
//

#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

// Definition for a binary tree node.
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
    TreeNode* invertTree(TreeNode* root) {
        
        stack<int> posStack;
        posOrder(root, posStack);
        preOrder(root, posStack);
        
        return root;
    }
    void posOrder(TreeNode* root, stack<int> &stack) {
        if (root == nullptr) {
            return;
        }
        posOrder(root->left, stack);
        posOrder(root->right, stack);
        cout << root->val << endl;
        stack.push(root->val);
    }
    void preOrder(TreeNode* root, stack<int> &stack) {
        if (root == nullptr) {
            return;
        }
        cout << root->val << endl;
        cout << stack.top() << endl;
        cout << endl;
        root->val = stack.top();
        stack.pop();
        preOrder(root->left, stack);
        preOrder(root->right, stack);
    }
};

class Solution1 {
public:
    TreeNode* invertTree(TreeNode* root) {
        invertSubTree(root);
        return root;
    }
    void invertSubTree(TreeNode* root) {
        if (nullptr == root) {
            return;
        }
        TreeNode * tmp = root->right;
        root->right = root->left;
        root->left = tmp;
        invertSubTree(root->left);
        invertSubTree(root->right);
    }
};

//先序遍历
class Solution2 {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return nullptr;
        swap(root->left,root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};

//后序遍历
class Solution3 {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return nullptr;
        invertTree(root->left);
        invertTree(root->right);
        swap(root->left,root->right);
        return root;
    }
};

//中序遍历
class Solution4 {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return nullptr;
        invertTree(root->left);
        swap(root->left,root->right);
        invertTree(root->left);
        return root;
    }
};

class Solution5 {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (nullptr == root) {
            return nullptr;
        }
        queue<TreeNode *> q;
        q.push(root);
        while (q.size() != 0) {
            TreeNode * node = q.front();
            q.pop();
            swap(node->left, node->right);
            if (node->left) {
                q.push(node->left);
            }
            if (node->right) {
                q.push(node->right);
            }
        }
        return root;
    }
};

void levelOrder(TreeNode * x) {
    if (nullptr == x) {
        return;
    }
    queue<TreeNode *> nodeQ;
    nodeQ.push(x);
    TreeNode * tmp = x;
    while (!nodeQ.empty()) {
        tmp = nodeQ.front();
        nodeQ.pop();
        cout << tmp->val << " ";
        if (tmp->left) nodeQ.push(tmp->left);
        if (tmp->right) nodeQ.push(tmp->right);
    }
    cout << endl;
}

int main(int argc, const char * argv[]) {
    
    TreeNode *root = new TreeNode(4);
    TreeNode *root1 = new TreeNode(2);
    TreeNode *root2 = new TreeNode(7);
    TreeNode *root3 = new TreeNode(1);
    TreeNode *root4 = new TreeNode(3);
    TreeNode *root5 = new TreeNode(6);
    TreeNode *root6 = new TreeNode(9);
    
    root->left = root1;
    root->right = root2;
    root1->left = root3;
    root1->right = root4;
    root2->left = root5;
    root2->right = root6;
    
    //    Solution s;
    //    s.invertTree(root);
    //    levelOrder(root);
    
    //    Solution1 s1;
    //    s1.invertTree(root);
    //    levelOrder(root);
    
//    Solution2 s2;
//    s2.invertTree(root);
//    levelOrder(root);
    
    Solution5 s5;
    s5.invertTree(root);
    levelOrder(root);
    
    //    TreeNode *root = new TreeNode(1);
    //    TreeNode *root1 = new TreeNode(2);
    //
    //    root->left = root1;
    //
    //    Solution s;
    //    s.invertTree(root);
    //    levelOrder(root);
    
    return 0;
}
