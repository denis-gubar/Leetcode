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
	enum CallState
	{
		Unprocessed,
		LeftSubtreeProcesseed,
		RightSubtreeProcessed
	};
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> result;
		stack<pair<TreeNode*, CallState>> S;
		S.push({ root, CallState::Unprocessed });
		while (!S.empty())
		{
			pair<TreeNode*, CallState> P = S.top(); S.pop();
			TreeNode* node = P.first;
			if (node)
			{
				CallState state = P.second;
				switch (state)
				{
				case Solution::Unprocessed:
					S.push({ node, LeftSubtreeProcesseed });
					S.push({ node->left, Unprocessed });
					break;
				case Solution::LeftSubtreeProcesseed:
					S.push({ node, RightSubtreeProcessed });
					S.push({ node->right, Unprocessed });
					break;
				case Solution::RightSubtreeProcessed:
					result.push_back(node->val);
					break;
				default:
					break;
				}
			}
		}
		return result;
	}
};