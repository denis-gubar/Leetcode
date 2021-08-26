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
	unordered_map<int, int> calc(TreeNode* root, int& result, int distance, int level = 0)
	{
		unordered_map<int, int> M;
		if (!root) return M;
		if (!root->left && !root->right)
		{
			++M[level];
			return M;
		}
		unordered_map<int, int> L = calc(root->left, result, distance, level + 1);
		unordered_map<int, int> R = calc(root->right, result, distance, level + 1);
		for (auto left : L)
			for (auto right : R)
				if (left.first - level + right.first - level <= distance)
					result += left.second * right.second;
		M = move(L);
		for (auto right : R)
			M[right.first] += right.second;
		return M;
	}
	int countPairs(TreeNode* root, int distance) {
		int result = 0;
		calc(root, result, distance);
		return result;
	}
};