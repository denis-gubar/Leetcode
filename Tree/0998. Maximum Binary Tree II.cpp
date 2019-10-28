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
	vector<int> calc(TreeNode* root)
	{
		if (!root)
			return {};
		vector<int> result = calc(root->left);
		result.push_back(root->val);
		vector<int> right = calc(root->right);
		copy(right.begin(), right.end(), back_inserter(result));
		return result;
	}
	TreeNode* construct(vector<int>::iterator begin, vector<int>::iterator end)
	{
		if (begin == end)
			return nullptr;
		auto it = max_element(begin, end);
		TreeNode * root = new TreeNode(*it);
		root->left = construct(begin, it);
		root->right = construct(it + 1, end);
		return root;
	}
	TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
		vector<int> Nodes = calc(root);
		Nodes.push_back(val);
		return construct(Nodes.begin(), Nodes.end());
	}
};