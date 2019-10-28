class Solution {
public:
	void collect(TreeNode* root, vector<int>& vals)
	{
		if (root)
		{
			vals.push_back(root->val);
			collect(root->left, vals);
			collect(root->right, vals);
		}
	}
	int findSecondMinimumValue(TreeNode* root) {
		vector<int> vals;
		collect(root, vals);
		sort(vals.begin(), vals.end());
		vals.erase(unique(vals.begin(), vals.end()), vals.end());
		if (vals.size() < 2)
			return -1;
		return vals[1];
	}
};