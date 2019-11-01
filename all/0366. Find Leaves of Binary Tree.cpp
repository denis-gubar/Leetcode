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
	bool calc(TreeNode* root, vector<vector<int>>& result)
	{
		if (!root) return false;
		if (!root->left && !root->right)
		{
			result.back().push_back(root->val);
			return true;
		}
		else
		{
			if (calc(root->left, result))
                root->left = nullptr;
			if (calc(root->right, result))
                root->right = nullptr;
		}
        return false;
	}
	vector<vector<int>> findLeaves(TreeNode* root) {
		vector<vector<int>> result;
        if (root)
        {
            do 
            {
                result.push_back({});			
            } while (!calc(root, result));
        }
		return result;
	}
};