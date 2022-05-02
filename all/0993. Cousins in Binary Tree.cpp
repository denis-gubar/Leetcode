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
	pair<TreeNode*, int> calc(TreeNode* root, int x, TreeNode* parent = nullptr, int level = 0)
	{
		if (!root) return {};
		if (root->val == x) return { parent, level };
		return max(calc(root->left, x, root, level + 1),
			calc(root->right, x, root, level + 1));
	}
	bool isCousins(TreeNode* root, int x, int y) {
		auto X = calc(root, x);
		auto Y = calc(root, y);
		return X.second == Y.second && X.first != Y.first;
	}
};