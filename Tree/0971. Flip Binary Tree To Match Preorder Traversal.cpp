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
	void calc(TreeNode* root, const vector<int>& voyage, vector<int>& nodes, vector<int>& result)
	{
		if (!root)
			return;
		nodes.push_back(root->val);
		if (nodes.size() < voyage.size() && root->left && root->right && voyage[nodes.size()] == root->right->val)
		{
			result.push_back(root->val);
			swap(root->left, root->right);
		}
		calc(root->left, voyage, nodes, result);
		calc(root->right, voyage, nodes, result);
	}
	vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
		vector<int> nodes, result;
		calc(root, voyage, nodes, result);
		if (nodes != voyage)
			return { -1 };
		return result;
	}
};