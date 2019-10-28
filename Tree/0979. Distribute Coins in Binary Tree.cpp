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
	pair<int, int> calc(TreeNode* root)
	{
		if (!root)
			return { 0, 0 };
		pair<int, int> L = calc(root->left), R = calc(root->right);
		int delta = L.first + R.first + root->val - 1;
		return { delta, L.second + R.second + abs(delta) };
	}
	int distributeCoins(TreeNode* root) {
		return calc(root).second;
	}
};