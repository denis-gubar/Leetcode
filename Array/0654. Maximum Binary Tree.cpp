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
	TreeNode* calc(vector<int>::iterator begin, vector<int>::iterator end)
	{
		if (begin == end)
			return nullptr;
		auto it = max_element(begin, end);
		TreeNode* root = new TreeNode(*it);
		root->left = calc(begin, it);
		root->right = calc(it + 1, end);
		return root;
	}
	TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
		return calc(nums.begin(), nums.end());
	}
};