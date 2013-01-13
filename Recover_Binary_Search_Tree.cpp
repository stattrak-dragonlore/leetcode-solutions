
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void inorder(TreeNode *root, vector<pair<TreeNode *, int> > &s)
{
    if (!root)
        return;
    inorder(root->left, s);
    s.push_back(make_pair(root, s.size()));
    inorder(root->right, s);
}

bool cmp(const pair<TreeNode *, int> &a, const pair<TreeNode *, int> &b)
{
    return a.first->val < b.first->val;
}

class Solution {
public:
    void recoverTree(TreeNode *root) {
        vector<pair<TreeNode *, int> > s;
        inorder(root, s);
        sort(s.begin(), s.end(), cmp);
        int i, j;
        for (i = 0; i < s.size(); i++) {
            if (i != s[i].second) {
                break;
            }
        }
        for (j = i + 1; j < s.size(); j++) {
            if (j != s[j].second) {
                break;
            }
        }
        swap(s[i].first->val, s[j].first->val);
        return;
    }
};
