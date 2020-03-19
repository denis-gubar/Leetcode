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
	int calc(TreeNode* root, bool isLeft, int sum)
	{
		if (!root) return sum;
        if (isLeft)
            root->val = ((root->val / 1000) | 1) * 1000;
        else
            root->val = ((root->val / 1000) | 2) * 1000;
		if (isLeft)
			return calc(root->left, !isLeft, sum + 1);
		return calc(root->right, !isLeft, sum + 1);
	}
	int traverse(TreeNode* root)
	{
		if (!root) return 0;
		int result = 0;
		if (((root->val / 1000) & 1) == 0)
			result = max(result, calc(root, true, 0));
		if (((root->val / 1000) & 2) == 0)
			result = max(result, calc(root, false, 0));
		result = max(result, traverse(root->left));
		result = max(result, traverse(root->right));
		return result;
	}
	int longestZigZag(TreeNode* root) {
		return max(0, traverse(root) - 1);
	}
};