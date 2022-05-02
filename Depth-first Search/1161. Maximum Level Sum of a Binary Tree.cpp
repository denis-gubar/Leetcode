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
	void calc(TreeNode* root, int level = 0)
	{
		if (!root) return;
		if (levels.size() == level)
			levels.push_back(0);
		levels[level] += root->val;
		calc(root->left, level + 1);
		calc(root->right, level + 1);
	}
	int maxLevelSum(TreeNode* root) {
		levels.clear();
		calc(root);
		return max_element(levels.begin(), levels.end()) - levels.begin() + 1;
	}
	vector<int> levels;
};