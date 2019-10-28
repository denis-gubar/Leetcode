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
	int result;
	int calc( TreeNode* root )
	{
		if (!root)
			return 0;
		int left = 0, right = 0;
		int a = calc( root->left );
		int b = calc( root->right );
		if (root->left && root->left->val == root->val)
			left = a + 1;
		if (root->right && root->right->val == root->val)
			right = b + 1;
		result = max( result, left + right );
		return max( left, right );
	}
	int longestUnivaluePath( TreeNode* root ) {
		result = 0;
		calc( root );
		return result;
	}
};