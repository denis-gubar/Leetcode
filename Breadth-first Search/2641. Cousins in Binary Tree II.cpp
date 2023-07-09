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
	void calc(TreeNode* root, int level = 0)
	{
		if (root)
		{
			if (Levels.size() == level)
				Levels.push_back({});
			Levels[level].push_back(root->val);
			if (root->left)
			{
				parents[root->left] = root;
				D[root] += root->left->val;
			}
			if (root->right)
			{
				parents[root->right] = root;
				D[root] += root->right->val;
			}
			calc(root->left, level + 1);
			calc(root->right, level + 1);
		}
	}
	void update(TreeNode* root, int level = 0)
	{
		if (root)
		{
			Levels[level].push_back(root->val);
			if (level > 0)
				root->val = sums[level] - D[parents[root]];
			else
				root->val = 0;
			update(root->left, level + 1);
			update(root->right, level + 1);
		}
	}
	vector<vector<int>> Levels;
	vector<int> sums;
	unordered_map<TreeNode*, TreeNode*> parents;
	unordered_map<TreeNode*, int> D;
    TreeNode* replaceValueInTree(TreeNode* root) {
		calc(root);
		for (int i = 0; i < Levels.size(); ++i)
			sums.push_back(accumulate(Levels[i].begin(), Levels[i].end(), 0));
		update(root);
		return root;
    }
};
