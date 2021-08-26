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
	void calc(TreeNode* root, vector<int>& result, bool isLonely = false)
	{
		if (!root) return;
		if (isLonely)
			result.push_back(root->val);
		calc(root->left, result, !root->right);
		calc(root->right, result, !root->left);
	}
	vector<int> getLonelyNodes(TreeNode* root) {
		vector<int> result;
		calc(root, result);
		return result;
	}
};