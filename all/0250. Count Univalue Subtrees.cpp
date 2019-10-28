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
	pair<int, int> calc(TreeNode* root, int& result)
	{
		if (!root)
			return {numeric_limits<int>::min(), numeric_limits<int>::max()};
		if (!root->left && !root->right)
		{
			++result;
			return { root->val, root->val };
		}
		if (root->left && !root->right)
		{
			pair<int, int> p = calc(root->left, result);
			if (p.first == p.second && p.first == root->val)
				++result;
			return { min(root->val, p.first), max(root->val, p.second) };
		}
		if (!root->left && root->right)
		{
			pair<int, int> p = calc(root->right, result);
			if (p.first == p.second && p.first == root->val)
				++result;
			return { min(root->val, p.first), max(root->val, p.second) };
		}
		pair<int, int> pLeft = calc(root->left, result);
		pair<int, int> pRight = calc(root->right, result);
		if (pLeft.first == pLeft.second && pRight.first == pRight.second && pLeft.first == pRight.first && pLeft.first == root->val)
			++result;
		return { min({root->val, pLeft.first, pRight.first}), max({root->val, pLeft.second, pRight.second}) };
	}
	int countUnivalSubtrees(TreeNode* root) {
		int result = 0;
		if (root)
			calc(root, result);
		return result;
	}
};