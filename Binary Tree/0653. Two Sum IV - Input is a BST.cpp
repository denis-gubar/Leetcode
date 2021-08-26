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
	bool calc(TreeNode* root, int k) {
		if (!root)
			return false;
		if (S.find(k - root->val) != S.end())
			return true;
		S.insert(root->val);
		return calc(root->left, k) || calc(root->right, k);
	}
	bool findTarget(TreeNode* root, int k) {
		S.clear();
		return calc(root, k);
	}
	unordered_set<int> S;
};