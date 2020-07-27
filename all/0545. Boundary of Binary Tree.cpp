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
	void calcLeftBoundary(TreeNode* root, vector<int>& result)
	{
		if (!root) return;
		result.push_back(root->val);
		if (root->left)
			calcLeftBoundary(root->left, result);
		else if (root->right)
			calcLeftBoundary(root->right, result);
	}
	void calcRightBoundary(TreeNode* root, vector<int>& result)
	{
		if (!root) return;
		if (root->right)
			calcRightBoundary(root->right, result);
		else if (root->left)
			calcRightBoundary(root->left, result);
		result.push_back(root->val);
	}
	void calc(TreeNode* root, vector<int>& result)
	{
		if (!root) return;
		if (!root->left && !root->right)
			result.push_back(root->val);
		calc(root->left, result);
		calc(root->right, result);
	}
	vector<int> boundaryOfBinaryTree(TreeNode* root) {
		vector<int>	result;
		if (root)
		{
			result.push_back(root->val);
			if (root->left)
			{
				calcLeftBoundary(root->left, result);
				result.pop_back();
				calc(root->left, result);
			}			
			if (root->right)
			{
				calc(root->right, result);
				result.pop_back();
				calcRightBoundary(root->right, result);
			}
		}
		return result;
	}
};