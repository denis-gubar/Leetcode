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
	int goodNodes(TreeNode* root, int x = -100'000) {
		if (!root) return 0;
		int result = root->val >= x;
		result += goodNodes(root->left, max(x, root->val));
		result += goodNodes(root->right, max(x, root->val));
		return result;
	}
};