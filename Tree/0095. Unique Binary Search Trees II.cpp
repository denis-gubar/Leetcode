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
	TreeNode* copy(TreeNode* root, int delta = 0)
	{
		if (!root) return nullptr;
		TreeNode* result = new TreeNode(root->val + delta);
		result->left = copy(root->left, delta);
		result->right = copy(root->right, delta);
		return result;
	}
	vector<TreeNode*> calc(int n, vector<vector<TreeNode*>>& F)
	{
		if (!F[n].empty()) return F[n];
		vector<TreeNode*> result;
		for (int root_val = 1; root_val <= n; ++root_val)
		{
			vector<TreeNode*> left = calc(root_val - 1, F);
			vector<TreeNode*> right = calc(n - root_val, F);
			for (auto L : left)
				for (auto R : right)
				{
					result.emplace_back(new TreeNode(root_val));
					result.back()->left = copy(L);
					result.back()->right = copy(R, root_val);
				}
		}
		return F[n] = move(result);
	}
	vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
		vector<vector<TreeNode*>> F(n + 1);
		F[0] = { nullptr };
		return calc(n, F);
	}
};