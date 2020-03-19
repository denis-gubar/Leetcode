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
	int calc(TreeNode*& root, int target)
	{
		if (!root) return 0;
        int result = 0;
        result += calc(root->left, target);
        result += calc(root->right, target);
		if (root->val == target && result == 0)
        {
            root->left = nullptr;
            root->right = nullptr;
            root->val = -1;
            //delete root;
            root = nullptr;
        }
        else
            ++result;
        return result;
	}
	TreeNode* removeLeafNodes(TreeNode*& root, int target) {
		calc(root, target);
		return root;            
	}
};