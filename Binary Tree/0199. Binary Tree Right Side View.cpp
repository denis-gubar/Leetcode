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
	void calc(TreeNode* root, vector<int>& result, int level = 0)
	{
		if (!root) return;
		if (result.size() == level)
			result.push_back(0);
		result[level] = root->val;
		calc(root->left, result, level + 1);
		calc(root->right, result, level + 1);
	}
	vector<int> rightSideView(TreeNode* root) {
		vector<int>	result;
		calc(root, result);
		return result;
	}
};