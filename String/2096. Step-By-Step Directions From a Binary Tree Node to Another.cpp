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
	int calc(TreeNode* root, int p, int q, TreeNode** result)
	{
		if (!root)
			return 0;
		int count = (root->val == p) + (root->val == q);
		count += calc(root->left, p, q, result);
		count += calc(root->right, p, q, result);
		if (count == 2 && !*result)
			*result = root;
		return count;
	}
	TreeNode* lowestCommonAncestor(TreeNode* root, int p, int q) {
		TreeNode* result = nullptr;
		calc(root, p, q, &result);
		return result;
	}
	TreeNode* find(TreeNode* root, int x)
	{
		if (!root)
			return nullptr;
		if (root->val == x)
			return root;
		TreeNode* result = find(root->left, x);
		if (!result)
			return find(root->right, x);
		return result;
	}
	void getParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parents)
	{
		if (!root)
			return;
		if (root->left)
		{
			parents[root->left] = root;
			getParents(root->left, parents);
		}
		if (root->right)
		{
			parents[root->right] = root;
			getParents(root->right, parents);
		}
	}
	bool getPath(TreeNode* root, int destValue, string& result)
	{
		if (!root)
			return false;
		if (root->val == destValue)
			return true;
		if (root->left)
		{
			result += 'L';
			if (!getPath(root->left, destValue, result))
				result.pop_back();
			else
				return true;
		}
		if (root->right)
		{
			result += 'R';
			if (!getPath(root->right, destValue, result))
				result.pop_back();
			else
				return true;
		}
		return false;
	}
	string getDirections(TreeNode* root, int startValue, int destValue) {
		TreeNode* commonAncestor = lowestCommonAncestor(root, startValue, destValue);
		unordered_map<TreeNode*, TreeNode*> parents;
		getParents(root, parents);
		string result;
		TreeNode* node = find(root, startValue);
		while (node != commonAncestor)
		{
			result += 'U';
			node = parents[node];
		}
		getPath(node, destValue, result);
		return result;
	}
};