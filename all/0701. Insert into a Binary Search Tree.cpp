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
	TreeNode* insertIntoBST(TreeNode* root, int val, TreeNode* node = nullptr) {
		if (!root) return new TreeNode(val);
		if (!node) return insertIntoBST(root, val, root);			
		if (node->val > val)
		{
			if (!node->left)
			{
				node->left = new TreeNode(val);
				return root;
			}
			return insertIntoBST(root, val, node->left);
		}
		if (!node->right)
		{
			node->right = new TreeNode(val);
			return root;
		}
		return insertIntoBST(root, val, node->right);
	}
};
