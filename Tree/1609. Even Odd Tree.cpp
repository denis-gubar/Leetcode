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
	void calc(TreeNode* root, vector<vector<int>>& levels, int level = 0)
	{
		if (!root) return;
		if (level == levels.size())
			levels.push_back({});
		levels[level].push_back(root->val);
		calc(root->left, levels, level + 1);
		calc(root->right, levels, level + 1);
	}
	bool isEvenOddTree(TreeNode* root) {
		vector<vector<int>> levels;
        levels.reserve(100'000);
        calc(root, levels);
		for (int i = 0; i < levels.size(); ++i)
        {
            for (int x : levels[i])
                if (i % 2 == x % 2)
                    return false;
			for (int j = 1; j < levels[i].size(); ++j)
				if (i % 2 == 0 && levels[i][j - 1] >= levels[i][j] ||
					i % 2 == 1 && levels[i][j - 1] <= levels[i][j])
					return false;
        }
		return true;
	}
};