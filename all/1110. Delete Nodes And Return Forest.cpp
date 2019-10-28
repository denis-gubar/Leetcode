/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	void calc(TreeNode* root, vector<int>& D)
	{
		if (!root)
			return;
		if (root->left)
		{
            bool flag = D[root->left->val];
			calc(root->left, D);
			if (flag)
				root->left = nullptr;
		}
		if (root->right)
		{
            bool flag = D[root->right->val];
			calc(root->right, D);
			if (flag)
				root->right = nullptr;
		}
		if (D[root->val])
		{
			if (root->left && !D[root->left->val])
				result.push_back(root->left);
			if (root->right && !D[root->right->val])
				result.push_back(root->right);
			//delete root;
		}
	}
	vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
		vector<int> D(1001);
		for (int d : to_delete)
			D[d] = 1;
		result.clear();
		calc(root, D);
        if (root && !D[root->val])
            result.push_back(root);
		return result;
	}
	vector<TreeNode*> result;
};