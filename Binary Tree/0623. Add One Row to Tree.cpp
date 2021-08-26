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
	TreeNode* addOneRow(TreeNode* root, int v, int d, int level = 1) {
        if (d == 1)
        {
            auto new_root = new TreeNode(v);
            new_root->left = root;
            return new_root;
        }
		if (root)
		{
			if (level == d - 1)
			{
                auto left = new TreeNode(v);
                left->left = root->left;
				root->left = left;
                auto right = new TreeNode(v);
				right->right = root->right;
				root->right = right;
			}
			else
			{
				root->left = addOneRow(root->left, v, d, level + 1);
				root->right = addOneRow(root->right, v, d, level + 1);
			}
		}
		return root;
	}
};