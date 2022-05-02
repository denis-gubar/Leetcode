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
	void traverse(TreeNode* root, vector<bool> const& M, vector<TreeNode*>& result)
	{
		if (!root) return;
		if (root->left)
		{
			bool flag = M[root->left->val];
			traverse(root->left, M, result);
			if (flag)
				root->left = nullptr;
		}
		if (root->right)
		{
			bool flag = M[root->right->val];
			traverse(root->right, M, result);
			if (flag)
				root->right = nullptr;
		}
		if (M[root->val])
		{
			if (root->left && !M[root->left->val])
				result.push_back(root->left);
			if (root->right && !M[root->right->val])
				result.push_back(root->right);
		}
	}
	vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {		
		vector<bool> M(1001);
		for (int x : to_delete)
			M[x] = true;
		vector<TreeNode*> result;
		traverse(root, M, result);
		if (root && !M[root->val])
			result.push_back(root);
		return result;
	}
};