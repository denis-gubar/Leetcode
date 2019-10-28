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
	bool isValidBST(TreeNode* root, int* leftMax = nullptr, int* rightMin = nullptr) {
		if (!root)
			return true;
		if (leftMax && root->val >= *leftMax || rightMin && root->val <= *rightMin)
			return false;
		return isValidBST(root->left, &root->val, rightMin) && isValidBST(root->right, leftMax, &root->val);
	}
};