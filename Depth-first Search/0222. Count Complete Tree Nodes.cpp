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
	int calc(TreeNode* root)
	{
		if (!root) return 0;
		return 1 + calc(root->left);
	}
	int countNodes(TreeNode* root) {
		if (!root)
			return 0;
		int height = calc(root);
		--height;
		int result = (1 << height) - 1;
		int a = 0, b = 1 << height;
		while (a + 1 < b)
		{
			int m = (a + b) / 2;
			TreeNode* node = root;
			for (int k = 0; k < height; ++k)
				if (m & (1 << (height - k - 1)))
					node = node->right;
				else
					node = node->left;
			if (node)
				a = m;
			else
				b = m;
		}
		return result + a + 1;
	}
};