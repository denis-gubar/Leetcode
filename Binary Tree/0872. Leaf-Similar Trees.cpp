class Solution {
public:
	void calc(TreeNode* node, vector<int>& leaves)
	{
		if (node)
		{
			if (!node->left && !node->right)
			{
				leaves.push_back(node->val);
				return;
			}
			if (node->left)
				calc(node->left, leaves);
			if (node->right)
				calc(node->right, leaves);
		}
	}
	bool leafSimilar(TreeNode* root1, TreeNode* root2) {
		vector<int> A, B;
		calc(root1, A);
		calc(root2, B);
		return A == B;
	}
};