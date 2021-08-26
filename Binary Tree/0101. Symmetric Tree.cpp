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
	bool calc(TreeNode* left, TreeNode* right)
	{
		if (!left && !right)
			return true;
		if (!left && right || left && !right)
			return false;
		if (left->val != right->val)
			return false;
		return calc(left->left, right->right) && calc(left->right, right->left);
	}
	bool isSymmetric(TreeNode* root) {
		if (!root)
			return true;
		return calc(root->left, root->right);
	}
};
