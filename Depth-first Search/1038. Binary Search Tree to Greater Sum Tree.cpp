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
	void calc(TreeNode* root, int& sum)
	{
		if (!root)
			return;
		calc(root->right, sum);
		sum += root->val;
		root->val = sum;
		calc(root->left, sum);
	}
	TreeNode* bstToGst(TreeNode* root) {
		int sum = 0;
		calc(root, sum);
		return root;
	}
};