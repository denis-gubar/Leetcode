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
	TreeNode* bstFromPreorder(vector<int>::iterator a, vector<int>::iterator b)
	{
		if (a == b)
			return nullptr;
		TreeNode* root = new TreeNode(*a);
		auto mid = a + 1;
		while (mid != b && *mid < *a)
			++mid;
		root->left = bstFromPreorder(a + 1, mid);
		root->right = bstFromPreorder(mid, b);
		return root;
	}
	TreeNode* bstFromPreorder(vector<int>& preorder) {
		return bstFromPreorder(preorder.begin(), preorder.end());
	}
};