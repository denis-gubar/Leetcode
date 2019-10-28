class Solution {
public:
	void calc(TreeNode* root, int sum)
	{
		if (!root)
			return;
		stack.push_back(root->val);
		if (!root->left && !root->right)
		{
			if (root->val == sum)
				result.push_back(stack);
		}
        else
        {
            calc(root->left, sum - root->val);
            calc(root->right, sum - root->val);
        }
		stack.pop_back();
	}
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		result.clear();
		stack.clear();
		calc(root, sum);
		return result;
	}
	vector<vector<int>> result;
	vector<int> stack;
};