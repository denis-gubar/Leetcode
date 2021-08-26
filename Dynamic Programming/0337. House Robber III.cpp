/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
	pair<int, int> calc(TreeNode* root)
	{
		if (!root) return { 0, 0 };		
		pair<int, int> left = calc(root->left);
		pair<int, int> right = calc(root->right);
		return {max(left.second + right.second + root->val, left.first + right.first), 
				max(left.second + right.second, left.first + right.first)};
	}
	int rob(TreeNode* root) {
		auto [rob, noRob] = calc(root);
		return max(rob, noRob);
	}
};