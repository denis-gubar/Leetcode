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
	TreeNode* findParent(TreeNode* root, int L, int R)
	{
		if (root)
		{
			if (root->val < L)
				return root->right;
			if (root->val > R)
				return root->left;
			return root;
		}
		return nullptr;
	}
	TreeNode* trim(TreeNode* root, int L, int R)
	{
		if (root)
		{
			root->left = trim(root->left, L, R);
			root->right = trim(root->right, L, R);
			if (root->val >= L && root->val <= R)
				return root;
            return root->left ? root->left : root->right;
		}
		return nullptr;
	}
	TreeNode* trimBST(TreeNode* root, int L, int R) {
		return trim(findParent(root, L, R), L, R);
	}
};