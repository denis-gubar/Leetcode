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
				bool isLeftSubtreeProcessed = P.second;
				if (!isLeftSubtreeProcessed)
				{
					result.push_back(node->val);
					S.push({ node, true });
					S.push({ node->left, false });
				}
				else
					S.push({ node->right, false });
			}
		}
		return result;
	}
	vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
		vector<int> result;
		vector<int> A = preorderTraversal(root1);
        sort(A.begin(), A.end());        
		vector<int> B = preorderTraversal(root2);
        sort(B.begin(), B.end());
		merge(A.begin(), A.end(), B.begin(), B.end(), back_inserter(result));
		return result;
	}
};