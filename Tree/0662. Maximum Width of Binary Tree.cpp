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
	void calc(TreeNode* root, int level, bitset<10000> path)
	{
		if (!root)
			return;
		if (levels.size() <= level)
			levels.push_back({});
		levels[level].push_back(path);
        path <<= 1;
		calc(root->left, level + 1, path);
        path[0] = 1;
		calc(root->right, level + 1, path);
	}
	int widthOfBinaryTree(TreeNode* root) {
		int result = 0;
		levels.clear();
		calc(root, 0, bitset<10000>());
        bitset<10000> mask;
        for(int i = 0; i < 32; ++i)
            mask[i] = 1;
		for (const vector<bitset<10000>>& level : levels)
			result = max<int>(result, (level.back() & mask).to_ulong() - (*level.begin() & mask).to_ulong() + 1);
		return result;
	}
	vector<vector<bitset<10000>>> levels;
};