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
	void convert(TreeNode* root, vector<int>& A)
	{
		if (!root) return;
		A.push_back(root->val);
		convert(root->left, A);
		convert(root->right, A);
	}
	bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
		vector<int> A, B;
		convert(root1, A);
		convert(root2, B);
		sort(A.begin(), A.end());
		for (int b : B)
			if (binary_search(A.begin(), A.end(), target - b))
				return true;
		return false;
	}
};