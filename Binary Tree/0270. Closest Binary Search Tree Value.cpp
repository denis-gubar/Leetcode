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
	int closestValue(TreeNode* root, double target) {
		if (!root)
			return 0;
		if (root->val > target)
		{
			int result = closestValue(root->left, target);
			if (!root->left || abs(result - target) > abs(root->val - target))
				return root->val;
			return result;
		}
		int result = closestValue(root->right, target);
		if (!root->right || abs(result - target) > abs(root->val - target))
			return root->val;
		return result;
	}
};