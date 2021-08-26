class Solution {
public:
	void calc(TreeNode* root, string& path, string& result)
	{
		if (!root)
			return;
		path.push_back(root->val + 'a');
		if (!root->left && !root->right)
		{
			string current(path);
			reverse(current.begin(), current.end());
			result = min(result, current);
		}
		calc(root->left, path, result);
		calc(root->right, path, result);
		path.pop_back();
	}
	string smallestFromLeaf(TreeNode* root) {
		string result = "~", path;
		calc(root, path, result);
		if (result == "~")
			result = "";
		return result;
	}
};