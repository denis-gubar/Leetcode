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
	int prev(TreeNode* root)
	{
		TreeNode* node = root->left;
		while (node->right)
			node = node->right;
		return node->val;
	}
	int next(TreeNode* root)
	{
		TreeNode* node = root->right;
		while (node->left)
			node = node->left;
		return node->val;
	}
	TreeNode* deleteNode(TreeNode* root, int key) {
		if (!root) return nullptr;
		if (key > root->val)
			root->right = deleteNode(root->right, key);
		else if (key < root->val)
			root->left = deleteNode(root->left, key);
		else
		{
			if (!root->left && !root->right)
                root = nullptr;
			else if (root->right)
			{
				root->val = next(root);
				root->right = deleteNode(root->right, root->val);
			}
			else
			{
				root->val = prev(root);
				root->left = deleteNode(root->left, root->val);
			}
		}
		return root;
	}
};