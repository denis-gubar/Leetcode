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
	void calc(TreeNode* root, int& k, int& result)
	{
		if (k <= 0 || !root)
			return;
		calc(root->left, k, result);
        if (--k == 0)
		    result = root->val;
		calc(root->right, k, result);
	}
	int kthSmallest(TreeNode* root, int k) {
		int result = 0;
		calc(root, k, result);
		return result;
	}
};