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
	int getHeight(TreeNode* root)
	{
		if (!root) return 0;
		return 1 + getHeight(root->left);
	}
	int countNodes(TreeNode* root) {
		int height = getHeight(root);
		if (!height) return 0;
		--height;
		int result = (1 << height) - 1;
		int a = 0, b = (1 << height) + 1;
		while (a + 1 < b)
		{
			int m = (a + b) / 2;
			vector<int>	digits;
			int n = m - 1;
			while (n)
			{
				digits.push_back(n % 2);
				n /= 2;
			}
			digits.resize(height, 0);
			reverse(digits.begin(), digits.end());
			TreeNode* node = root;
			for (int i = 0; i < digits.size(); ++i)
				if (digits[i])
					node = node->right;
				else
					node = node->left;
			if (node)
				a = m;
			else
				b = m;
		}
		return result + a;
	}
};