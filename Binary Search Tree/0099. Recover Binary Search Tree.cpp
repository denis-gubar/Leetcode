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
	void calc(TreeNode* root, vector<TreeNode*>& A)
	{
		if (!root) return;
		calc(root->left, A);
		A.push_back(root);
		calc(root->right, A);
	}
	void recoverTree(TreeNode* root) {
		vector<TreeNode*> A;
		calc(root, A);
		vector<TreeNode*> B(A);
		sort(B.begin(), B.end(), [](TreeNode* a, TreeNode* b)
			{
				return a->val < b->val;
			});
		vector<TreeNode*> S;
		for (int i = 0; i < A.size(); ++i)
			if (A[i] != B[i])
				S.push_back(A[i]);
		swap(S[0]->val, S[1]->val);
	}
};