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
	int size(TreeNode* root)
	{
		if (!root)
			return 0;
		return count[root] = 1 + size(root->left) + size(root->right);
	}
	int add(TreeNode* root)
	{
		if (!root)
			return 0;
		return sum[root] = root->val + add(root->left) + add(root->right);
	}
	double maximumAverageSubtree(TreeNode* root) {
		count.clear();
		sum.clear();
		size(root);
		add(root);
		vector<double> result;
		for (auto m : count)
		{
			TreeNode* node = m.first;
			result.push_back(1.0 * sum[node] / m.second);
		}
		return *max_element(result.begin(), result.end());
	}
	map<TreeNode*, int> count; 
	map<TreeNode*, int> sum;
};