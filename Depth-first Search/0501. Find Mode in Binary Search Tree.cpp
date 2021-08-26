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
	void calc(TreeNode* root, map<int, int>& M, int& best, vector<int>& result)
	{
		if (root)
		{
			int current = ++M[root->val];
			if (current > best)
			{
				result.clear();
				best = current;
			}
			if (current == best)
				result.push_back(root->val);
			calc(root->left, M, best, result);
			calc(root->right, M, best, result);
		}
	}
	vector<int> findMode(TreeNode* root) {
		vector<int> result;
		map<int, int> M;
		int best = 0;
		calc(root, M, best, result);
		return result;
	}
};