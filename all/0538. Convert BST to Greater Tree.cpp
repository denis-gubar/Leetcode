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
	int process(TreeNode* root, int parentSum = 0)
	{
		if (!root)
			return 0;
		int result = root->val + process(root->right, parentSum);		
		root->val = result + parentSum;
		return result + process(root->left, parentSum + result);
	}
	TreeNode* convertBST(TreeNode* root) {
		process(root);
		return root;
	}
};