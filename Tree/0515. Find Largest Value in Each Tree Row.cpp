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
	void calc(vector<int>& result, TreeNode* root, int level = 0)
	{
		if (!root)
			return;
		if (level == result.size())
			result.push_back(root->val);
		result[level] = max(result[level], root->val);
		calc(result, root->left, level + 1);
		calc(result, root->right, level + 1);
	}
	vector<int> largestValues(TreeNode* root) {
		vector<int> result;
		calc(result, root);
		return result;
	}
};