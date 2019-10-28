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