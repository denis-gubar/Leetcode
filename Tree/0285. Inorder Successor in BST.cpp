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
	TreeNode* calc(TreeNode* root, TreeNode* p, bool& isFound)
	{
		if (!root)
			return nullptr;
		TreeNode* result = calc(root->left, p, isFound);
		if (result)
			return result;
		if (isFound)
			return root;
		isFound = p == root;
		result = calc(root->right, p, isFound);
		return result;
	}
	TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
		bool isFound = false;
		return calc(root, p, isFound);
	}
};