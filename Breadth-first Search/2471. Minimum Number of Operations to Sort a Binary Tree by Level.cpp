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
	int minimumOperations(TreeNode* root) {
        int result = 0;
		vector<vector<int>> levels;
		calc(root, levels);
		for (int i = 0; i < levels.size(); ++i)
		{
			int N = levels[i].size();
			vector<pair<int, int>> P(N);
			unordered_map<int, int> M;
			for (int j = 0; j < N; ++j)
			{
				P[j] = { levels[i][j], j };
				M[levels[i][j]] = j;
			}
			sort(P.begin(), P.end());
			for (int j = 0; j < levels[i].size(); ++j)
			{
				if (levels[i][j] != P[j].first)
				{
					int v = P[j].first;
					int k = M[v];
					swap(levels[i][j], levels[i][k]);
					swap(M[levels[i][j]], M[levels[i][k]]);
					++result;
				}
			}
		}
        return result;
    }
};
