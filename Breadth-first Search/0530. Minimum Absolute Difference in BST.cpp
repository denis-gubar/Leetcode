class Solution {
public:
	void traverse(TreeNode* root, int& result, int& prev)
	{
		if (!root) return;
		traverse(root->left, result, prev);
		if (prev > -1)
			result = min(result, root->val - prev);
		prev = root->val;
		traverse(root->right, result, prev);
	}
	int getMinimumDifference(TreeNode* root) {
		int result = numeric_limits<int>::max();
		int prev = -1;
		traverse(root, result, prev);
		return result;
	}
};