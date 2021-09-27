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
	int sum(TreeNode* root)
	{
		if (!root) return 0;
		return root->val + sum(root->left) + sum(root->right);
	}
	pair<int, bool> calc(TreeNode* root, int total, bool isRoot = true)
	{
		if (!root) return { 0, false };
		auto [leftSum, leftResult] = calc(root->left, total, false);
		if (leftResult)
			return { leftSum, leftResult };
		auto [rightSum, rightResult] = calc(root->right, total, false);
		if (rightResult || isRoot)
			return { rightSum, rightResult };
		int subtreeSum = root->val + leftSum + rightSum;
		return { subtreeSum, subtreeSum + subtreeSum == total };

	}
	bool checkEqualTree(TreeNode* root) {		
		return calc(root, sum(root)).second;
	}
};