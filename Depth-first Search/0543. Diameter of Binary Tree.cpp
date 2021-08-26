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
	int calc(TreeNode* root, int& result)
	{
		if (!root) return 0;
		int left = 1 + calc(root->left, result);
		int right = 1 + calc(root->right, result);
		result = max(result, left + right - 2);
		return max(left, right);
	}
	int diameterOfBinaryTree(TreeNode* root) {
		int result = 0;
		calc(root, result);
		return result;
	}
};