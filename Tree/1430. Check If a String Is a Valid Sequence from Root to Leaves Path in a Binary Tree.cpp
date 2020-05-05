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
	bool isValidSequence(TreeNode* root, vector<int>& arr, int pos = 0, bool hasSibling = false) {
		if (!root)
			return !hasSibling && arr.size() == pos;
		if (arr.size() == pos || root->val != arr[pos])
			return false;
		return isValidSequence(root->left, arr, pos + 1, root->right) ||
			isValidSequence(root->right, arr, pos + 1, root->left);
	}
};