/*
  Validate Binary Search Tree
Given a binary tree, determine if it is a valid binary search tree.
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int last = INT_MIN;

//recursive version
bool inorder(TreeNode *root)
{
    if (!root)
        return true;
    if (!inorder(root->left))
        return false;
    if (root->val <= last) {
        return false;
    } else {
        last = root->val;
    }
    return inorder(root->right);
}

//iterative version
bool inorder2(TreeNode *root)
{
    int last = INT_MIN;
    if (!root)
        return true;
    stack<TreeNode *> s;
    TreeNode *r = root;
    while (1) {
        if (r) {
            s.push(r);
            r = r->left;
        } else {
            if (s.empty())
                break;
            r = s.top();
            s.pop();
            if (r->val <= last) {
                return false;
            } else {
                last = r->val;
            }
            r = r->right;
        }
    }
    return true;
}

class Solution {
public:
    bool isValidBST(TreeNode *root) {
        return inorder2(root);
    }
};
