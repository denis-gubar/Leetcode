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
	struct Data
	{
		bool isBST;
		int left;
		int right;
		int sum;
		int result;
	};
	Data calc(TreeNode* root)
	{
		if (!root)
			return {};
		Data result{ true, root->val, root->val, root->val, 0 };
		if (root->left)
		{
			Data left = calc(root->left);
			result.sum += left.sum;
			result.result = max(result.result, left.result);
			result.isBST &= left.isBST;
			result.isBST &= left.right < result.left;
			result.left = left.left;
		}
		if (root->right)
		{
			Data right = calc(root->right);
			result.sum += right.sum;
			result.result = max(result.result, right.result);
			result.isBST &= right.isBST;
			result.isBST &= right.left > result.right;
			result.right = right.right;
		}
		if (result.isBST)
			result.result = max(result.result, result.sum);
		return result;
	}
	int maxSumBST(TreeNode* root) {
		Data result = calc(root);
		return result.result;
	}
};