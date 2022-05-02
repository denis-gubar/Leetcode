class Solution {
public:
	int calc(TreeNode* root, map<vector<int>, int>& groups, vector<int>& count, vector<TreeNode*>& result)
	{
		if (!root) return -1;
		vector<int> key{ root->val, calc(root->left, groups, count, result), calc(root->right, groups, count, result) };
		auto it = groups.find(key);
		int groupId = groups.size();
		if (it == groups.end())
		{
			groups[key] = groupId;
			count.push_back(1);
		}
		else
		{
			groupId = it->second;
			if (++count[groupId] == 2)
				result.push_back(root);
		}
		return groupId;
	}
	vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
		vector<TreeNode*> result;
		map<vector<int>, int> groups;
		vector<int> count;
		calc(root, groups, count, result);
		return result;
	}
};