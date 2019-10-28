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
	const int MOD = 1'000'000'007;
	int sumRootToLeaf(TreeNode* root, int prefix = 0) {
		if (!root)
			return prefix;
		if (!root->left && !root->right)
			return (prefix * 2 % MOD + root->val) % MOD;
		int result = 0;
		if (root->left)
        {
			result += sumRootToLeaf(root->left, prefix * 2 % MOD + root->val);
            result %= MOD;
        }
		if (root->right)
        {
			result += sumRootToLeaf(root->right, prefix * 2 % MOD + root->val);
            result %= MOD;
        }
		return result % MOD;
	}
};