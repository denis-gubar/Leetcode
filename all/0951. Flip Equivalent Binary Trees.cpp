class Solution {
public:
	void calc(TreeNode* root, vector<int>& A)
	{
		if (root != nullptr)
		{
			A.push_back(root->val);
			if (root->left && root->right)
			{
				if (root->left->val < root->right->val)
				{
					A.push_back(root->left->val);
					A.push_back(root->right->val);
					calc(root->left, A);
					calc(root->right, A);
				}
				else
				{
					A.push_back(root->right->val);
					A.push_back(root->left->val);
					calc(root->right, A);
					calc(root->left, A);
				}
			}
			else
			{
				if (root->left)
				{
					A.push_back(root->left->val);
					calc(root->left, A);
				}
				if (root->right)
				{
					A.push_back(root->right->val);
					calc(root->right, A);
				}
			}
			A.push_back(root->val);
		}
	}
	bool flipEquiv(TreeNode* root1, TreeNode* root2) {
		vector<int> A, B;
        A.reserve(100);
        B.reserve(100);
		calc(root1, A);
		calc(root2, B);
		return A == B;
	}
};