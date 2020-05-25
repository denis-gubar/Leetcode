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
	int calc(TreeNode* root, vector<int>& digits)
	{
		if (!root) return 0;
		++digits[root->val];
		int result = 0;
		if (!root->left && !root->right)
		{
			if (*max_element(digits.begin(), digits.end()) == 0)
				return 0;
			int oddCount = 0;
			for (int d : digits)
				oddCount += d % 2;
			result = oddCount <= 1;
		}
		if (root->left)
			result += calc(root->left, digits);
		if (root->right)
			result += calc(root->right, digits);
		--digits[root->val];
		return result;
	}
	int pseudoPalindromicPaths(TreeNode* root) {
		vector<int> digits(10);
		return calc(root, digits);
	}
};