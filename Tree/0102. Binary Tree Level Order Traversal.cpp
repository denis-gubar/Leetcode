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
	void calc(TreeNode* root, vector<vector<int>>& result, int level = 0)
	{
		if (!root)
			return;
		if (result.size() == level)
			result.push_back({ root->val });
		else
			result[level].push_back(root->val);
		calc(root->left, result, level + 1);
		calc(root->right, result, level + 1);
	}
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> result;
		calc(root, result);
		return result;
	}
};