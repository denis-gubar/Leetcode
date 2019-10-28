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
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> result;
		stack<pair<TreeNode*, bool>> S;
		S.push({ root, false });
		TreeNode* node = root;
		while (!S.empty())
		{
			pair<TreeNode*, bool> P = S.top(); S.pop();
			node = P.first;
			if (node)
			{
				bool isLeftSubtreeProcessed = P.second;
				if (!isLeftSubtreeProcessed)
				{
					S.push({ node, true });
					S.push({ node->left, false });
				}
				else
				{
					result.push_back(node->val);
					S.push({ node->right, false });
				}
			}
		}
		return result;
	}
};