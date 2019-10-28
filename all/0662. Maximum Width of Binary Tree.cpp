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
	void calc(TreeNode* root, int level, int path)
	{
		if (!root)
			return;
		if (levels.size() <= level)
			levels.push_back({});
		levels[level].push_back(path);
		calc(root->left, level + 1, path * 2);
		calc(root->right, level + 1, path * 2 + 1);
	}
	int widthOfBinaryTree(TreeNode* root) {
		int result = 0;
		levels.clear();
		calc(root, 0, 0);
		for (const vector<int>& level : levels)
			result = max(result, *max_element(level.begin(), level.end()) - *min_element(level.begin(), level.end()) + 1);
		return result;
	}
	vector<vector<int>> levels;
};