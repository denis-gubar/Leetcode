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
	void calc(TreeNode* root, int level, vector<vector<int>>& Levels)
	{
		if (root)
		{
			if (Levels.size() == level)
				Levels.push_back({});
			Levels[level].push_back(root->val);
			calc(root->left, level + 1, Levels);
			calc(root->right, level + 1, Levels);
		}
	}
	vector<double> averageOfLevels(TreeNode* root) {
		vector<vector<int>> Levels;
		calc(root, 0, Levels);
		vector<double> result;
		for (vector<int>& level : Levels)
			result.push_back(accumulate(level.begin(), level.end(), 0.0) / level.size());
		return result;
	}
};