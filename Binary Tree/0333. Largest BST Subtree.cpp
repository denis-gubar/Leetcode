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
	struct Answer
	{
		bool isBst;
		int left;
		int right;
		int result;
	};
	int best;
	Answer calc(TreeNode* root) {
		if (!root)
			return { true, 0, 0, 0 };
		Answer leftResult = calc(root->left);
		Answer rightResult = calc(root->right);
		Answer result{};
		if ( (!root->left || leftResult.right < root->val) && 
			(!root->right || rightResult.left > root->val) )
		{
			result = {
				leftResult.isBst && rightResult.isBst,
				!root->left ? root->val : leftResult.left,
				!root->right ? root->val : rightResult.right,
				1 + leftResult.result + rightResult.result
			};
		}
		if (result.isBst)
			best = max(best, result.result);
		return result;
	}
	int largestBSTSubtree(TreeNode* root) {
		best = 0;
		calc(root);
		return best;
	}
};