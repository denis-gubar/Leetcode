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
	void collect(TreeNode* root, vector<int>& vals)
	{
		if (root)
		{
            collect(root->left, vals);
            vals.push_back(root->val);			
			collect(root->right, vals);
		}
	}
	TreeNode* increasingBST(TreeNode* root) {
		vector<int> vals;
		collect(root, vals);
		TreeNode* result = new TreeNode(vals[0]);
		TreeNode* node = result;
		for (int i = 1; i < vals.size(); ++i)
		{
			TreeNode* newNode = new TreeNode(vals[i]);
			node->right = newNode;
			node = newNode;
		}
		return result;
	}
};