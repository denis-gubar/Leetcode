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
	void calc(TreeNode* root, vector<TreeNode*>& nodes)
	{
		if (!root)
			return;
		calc(root->left, nodes);
		nodes.push_back(root);
		calc(root->right, nodes);
	}
	TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
		vector<TreeNode*> nodes;
		calc(root, nodes);
		nodes.push_back(nullptr);
		return *(find(nodes.begin(), nodes.end(), p) + 1);
	}
};