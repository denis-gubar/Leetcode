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
	using Iterator = vector<int>::iterator;
	TreeNode* calc(Iterator pre_first, Iterator pre_last, Iterator in_first, Iterator in_last)
	{
		if (pre_first == pre_last) return nullptr;
		TreeNode* root = new TreeNode(*pre_first);
		auto in_middle = find(in_first, in_last, *pre_first);
        ++pre_first;
		auto delta = in_middle - in_first;
		root->left = calc(pre_first, pre_first + delta, in_first, in_middle);
		root->right = calc(pre_first + delta, pre_last, in_middle + 1, in_last);
		return root;
	}
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		return calc(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
	}
};