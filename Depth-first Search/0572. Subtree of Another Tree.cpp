/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	bool calc(TreeNode* s, TreeNode* t)
	{
		if (!t) return !s;
		return s && s->val == t->val && calc(s->left, t->left) && calc(s->right, t->right);
	}
	bool isSubtree(TreeNode* s, TreeNode* t) {
		if (!s) return !t;
		if (calc(s, t))
			return true;
		return isSubtree(s->left, t) || isSubtree(s->right, t);
	}
};