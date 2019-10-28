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
	void calc(TreeNode* root, int level, vector<vector<int>>& nodes)
	{
		if (!root)
			return;
		if (level == nodes.size())
			nodes.push_back({ root->val });
		else
			nodes[level].push_back(root->val);
		calc(root->left, level + 1, nodes);
		calc(root->right, level + 1, nodes);
	}
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> result;
		calc(root, 0, result);
		for (int i = 1; i < result.size(); i += 2)
			reverse(result[i].begin(), result[i].end());
		return result;
	}
};