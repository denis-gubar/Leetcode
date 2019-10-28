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
	TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p, TreeNode* acc = nullptr) {
		if (!root)
			return nullptr;
		if (root == p)
			return p->left ? p->left : (p->right ? p->right : acc);
		if (root->val > p->val)
			return inorderSuccessor(root->left, p, root->right ? root->right : acc);
		return inorderSuccessor(root->right, p, acc);
	}
};