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
	void calc(TreeNode* root, int x, int y, vector<vector<int>>& Nodes)
	{
		if (!root)
			return;
		Nodes.push_back({ x, y, root->val });
		calc(root->left, x - 1, y + 1, Nodes);
		calc(root->right, x + 1, y + 1, Nodes);
	}
	vector<vector<int>> verticalTraversal(TreeNode* root) {
		vector<vector<int>> Nodes;
		calc(root, 0, 0, Nodes);
		vector<vector<int>> result;
		sort(Nodes.begin(), Nodes.end());
		for (int i = 0; i < Nodes.size(); ++i)
		{
			if (result.empty() || Nodes[i][0] != Nodes[i - 1][0])
				result.push_back({});
			result.back().push_back(Nodes[i][2]);
		}
		return result;
	}
};