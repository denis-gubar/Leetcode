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
	int sumNumbers(TreeNode* root, int prefix = 0) {
		if (!root)
			return 0;
		if (!root->left && !root->right)
			return prefix * 10 + root->val;
		return (root->left ? sumNumbers(root->left, prefix * 10 + root->val) : 0) +
			   (root->right ? sumNumbers(root->right, prefix * 10 + root->val) : 0);
	}
};