class Solution {
public:
	map<int, vector<int>> connectivity;
	void calc(TreeNode* node)
	{
		if (node->right)
		{
			connectivity[node->val].push_back(node->right->val);
			connectivity[node->right->val].push_back(node->val);
			calc(node->right);
		}
		if (node->left)
		{
			connectivity[node->val].push_back(node->left->val);
			connectivity[node->left->val].push_back(node->val);
			calc(node->left);
		}
	}
	vector<int> result;
	void find(int v, int from, int K)
	{
		if (!K)
		{
			result.push_back(v);
			return;
		}
		for (int u : connectivity[v])
			if (u != from)
				find(u, v, K - 1);
	}
	vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
		connectivity = map<int, vector<int>>();
		calc(root);
		result = vector<int>();
		find(target->val, target->val, K);
		return result;
	}
};