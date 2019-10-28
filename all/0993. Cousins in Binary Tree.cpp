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
	void calc(TreeNode* root, int level, map<int, int>& Parents, map<int, int>& Levels)
	{
		if (root)
		{
			Levels[root->val] = level;
			if (root->left)
				Parents[root->left->val] = root->val;
			if (root->right)
				Parents[root->right->val] = root->val;
			calc(root->left, level + 1, Parents, Levels);
			calc(root->right, level + 1, Parents, Levels);
		}
	}
	bool isCousins(TreeNode* root, int x, int y) {
		map<int, int> Parents, Levels;
		calc(root, 0, Parents, Levels);
		return Levels[x] == Levels[y] && Parents[x] != Parents[y];
	}
};