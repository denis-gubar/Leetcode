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
	void calc(TreeNode* root, int level, int path, vector<vector<int>>& levels)
	{
		if (!root || level > 10)
			return;
		if (levels.size() <= level)
			levels.push_back(vector<int>(1 << level));
		++levels[level][path];
		calc(root->left, level + 1, path * 2, levels);
		calc(root->right, level + 1, path * 2 + 1, levels);
	}
	bool isCompleteTree(TreeNode* root) {
		vector<vector<int>> levels;
		calc(root, 0, 0, levels);
		for (int i = 0; i + 1 < levels.size(); ++i)
			if (accumulate(levels[i].begin(), levels[i].end(), 0) != (1 << i))
				return false;
		if (!levels.empty())
		{
			levels.back().erase(unique(levels.back().begin(), levels.back().end()), levels.back().end());
			if (levels.back()[0] != 1 || levels.back().size() > 2)
				return false;
		}
		return true;
	}
};