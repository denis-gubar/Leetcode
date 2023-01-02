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
	int rangeSumBST(TreeNode* root, int L, int R) {
		if (!root)
			return 0;
		int result = 0;
		if (L <= root->val && root->val <= R)
			result += root->val;
		result += rangeSumBST(root->left, L, R);
		result += rangeSumBST(root->right, L, R);
		return result;
	}
};