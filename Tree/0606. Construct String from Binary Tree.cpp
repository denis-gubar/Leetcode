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
	string tree2str(TreeNode* root) {
		if (!root)
			return "";
		string result = to_string(root->val);
        if (root->right || root->left)
            result += "(" + tree2str(root->left) + ")";
		if (root->right)
			result += "(" + tree2str(root->right) + ")";
		return result;
	}
};