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
	int sum(TreeNode* root, int& tilt)
	{
		if (!root)
			return 0;
		int L = sum(root->left, tilt);
		int R = sum(root->right, tilt);
		tilt += abs(L - R);
		return root->val + L + R;
	}
	int findTilt(TreeNode* root) {
		int result = 0;
		sum(root, result);
		return result;
	}
};