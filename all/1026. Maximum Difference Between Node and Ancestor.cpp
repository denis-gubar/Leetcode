/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
	int calc(TreeNode* root, int A, int B)
	{
		int x = root->val;
		int y = max(abs(A - x), abs(B - x));
		if (!root->left && !root->right)
			return y;
		if (!root->left)
			return max(y, calc(root->right, min(A, x), max(B, x)));
		if (!root->right)
			return max(y, calc(root->left, min(A, x), max(B, x)));
		return max(y, max(calc(root->left, min(A, x), max(B, x)),
			calc(root->right, min(A, x), max(B, x))));
	}
	int maxAncestorDiff(TreeNode* root) {
		int x = root->val;
		if (!root->left)
			return calc(root->right, x, x);
		if (!root->right)
			return calc(root->left, x, x);
		return max(calc(root->left, x, x), calc(root->right, x, x));
	}
};