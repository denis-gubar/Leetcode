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
	void calc(TreeNode* root, vector<vector<int>>& nodes, int row, int column)
	{
		if (!root)
			return;
		nodes.push_back({ column, row, root->val });
		calc(root->left, nodes, row + 1, column - 1);
		calc(root->right, nodes, row + 1, column + 1);
	}
	vector<vector<int>> verticalOrder(TreeNode* root) {
		vector<vector<int>> result;
		if (!root)
			return result;
		vector<vector<int>> nodes;
		calc(root, nodes, 0, 0);
		stable_sort(nodes.begin(), nodes.end(), [](const vector<int>& a, const vector<int>&  b)
		{
			if (a[0] != b[0])
				return a[0] < b[0];
			return a[1] < b[1];
		}
		);
		result.push_back({ nodes[0][2] });
		for (int i = 1; i < nodes.size(); ++i)
		{
			if (nodes[i][0] != nodes[i - 1][0])
				result.push_back({});
			result.back().push_back(nodes[i][2]);
		}
		return result;
	}
};