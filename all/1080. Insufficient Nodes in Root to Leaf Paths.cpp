class Solution {
public:
	int calc(TreeNode* root, int limit)
	{
		if (!root)
			return 0;
		limit += root->val;
		int MaxSum = 0;
		if (!root->left && !root->right)
			MaxSum = limit;
		else
		{
			int left = root->left ? calc(root->left, limit) : -1;
			if (left < 0)
			{
				Delete(root->left);
				root->left = nullptr;
			}
			int right = root->right ? calc(root->right, limit) : -1;
			if (right < 0)
			{
				Delete(root->right);
				root->right = nullptr;
			}
			MaxSum = max(left, right);
		}
		return MaxSum;
	}
	static void Delete(TreeNode* root)
	{
		if (!root)
			return;
		if (root->left)
			Delete(root->left);
		if (root->right)
			Delete(root->right);
		delete root;
	}
	TreeNode* sufficientSubset(TreeNode* root, int limit) {		
		if (calc(root, -limit) < 0)
		{
		//	Delete(root);
			return nullptr;
		}
		return root;
	}
};