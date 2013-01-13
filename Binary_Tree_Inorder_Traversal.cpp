/*
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?

OJ's Binary Tree Serialization:
The serialization of a binary tree follows a level order traversal,
where '#' signifies a path terminator where no node exists below.

Here's an example:
   1
  / \
 2   3
    /
   4
    \
     5
The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}".

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
void inorder_r(TreeNode *root, vector<int> &r)
{
	if (!root)
		return;
	inorder(root->left, r);
	r.push_back(root->val);
	inorder(root->right, r);
}


void inorder(TreeNode *root, vector<int> &r)
{
	stack<TreeNode *> s;
	TreeNode *rr = root;
	while (1) {
		if (rr) {
			s.push(rr);
			rr = rr->left;
		} else {
			if (s.empty()) {
				break;
			}
			TreeNode *t = s.top();
			s.pop();
			r.push_back(t->val);

			rr = t->right;
		}
	}
}
/*
void postorder(TreeNode *root, vector<int> &r)
{
	stack<TreeNode *> s;
	TreeNode *c = root;
	while (1) {
		if (c) {
			s.push(c);
			prev = c;
			c = c->left;

		} else {
			t = s.top();

			if (prev == t) {
				c = t->right;
				prev = t;
			}
		}
	}
}
*/

class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
		vector<int> result;
		inorder(root, result);
		return result;
    }
};
