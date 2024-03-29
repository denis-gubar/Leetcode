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
	vector<int> preorderTraversal(TreeNode* root) {
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
				bool const& isLeftSubtreeProcessed = P.second;
				if (!isLeftSubtreeProcessed)
				{
					result.push_back(node->val);
					S.push({ node, true });
					S.push({ node->left, false });
				}
				else
					S.push({node->right, false});
			}
		}
		return result;
	}
};
