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
	struct ReturnData
	{
		int node;
		int children;
		int parent;
	};
	ReturnData calc(TreeNode* root)
	{
		if (!root)
			return {0, 0, 0};
		ReturnData result;
		ReturnData left = calc(root->left);
		ReturnData right = calc(root->right);
		result.node = 1 + min({ left.node, left.children, left.parent }) + min({ right.node, right.children, right.parent });
		result.children = min(max(1, left.node) + min({ right.node, right.children }),
			max(1, right.node) + min({ left.node, left.children }));
		result.parent = min(left.node, left.children) + min(right.node, right.children);
		return result;
	}
	int minCameraCover(TreeNode* root) {
		ReturnData result = calc(root);
		return min(result.children, result.node);
	}
};
