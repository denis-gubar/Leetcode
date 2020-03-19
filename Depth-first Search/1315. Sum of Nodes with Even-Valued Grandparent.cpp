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
	int sumEvenGrandparent(TreeNode* root, int level = 0) {
		if (!root) return 0;
		int result = 0;
		if (level & 2)
			result += root->val;
		int nextLevel = level % 2 * 2 + (root->val % 2 == 0);
		result += sumEvenGrandparent(root->left, nextLevel);
		result += sumEvenGrandparent(root->right, nextLevel);
		return result;
	}
};