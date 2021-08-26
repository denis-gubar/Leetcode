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
	pair<int, int> calc(TreeNode* root)
	{
		if (!root) return {};
		pair<int, int> left, right;
        left = calc(root->left);
        right = calc(root->right);
		if (root->left)
        {
			if (root->left->val + 1 != root->val)                
                left.first = 0;
            if (root->left->val - 1 != root->val)
                left.second = 0;
        }
        ++left.first;
        ++left.second;
		if (root->right)
        {
			if (root->right->val + 1 != root->val)                
                right.first = 0;
            if (root->right->val - 1 != root->val)
                right.second = 0;
        }
        ++right.first;
        ++right.second;
        int prev_result = result;
		result = max({ result, left.first + right.second - 1, left.second + right.first - 1 });
        return {max(left.first, right.first), max(left.second, right.second)};
	}
	int longestConsecutive(TreeNode* root) {
		result = 0;
		calc(root);
		return result;
	}
	int result;
};