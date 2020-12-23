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
	TreeNode* calc(TreeNode* root, TreeNode* u, int level, int& uLevel)
	{
		if (!root)
			return nullptr;
		if (level == uLevel)
			return root;
		if (root == u)
			uLevel = level;
		TreeNode* result = calc(root->left, u, level + 1, uLevel);
		if (result)
			return result;
		return calc(root->right, u, level + 1, uLevel);
	}
	TreeNode* findNearestRightNode(TreeNode* root, TreeNode* u) {
		int uLevel = -1;
		return calc(root, u, 0, uLevel);
	}
};