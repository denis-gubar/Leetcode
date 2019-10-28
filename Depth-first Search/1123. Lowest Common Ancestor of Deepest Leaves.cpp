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
	void calcDepth(TreeNode* root, int d = 0)
	{
		if (!root) return;
        depth[root] = d;
		calcDepth(root->left, d + 1);
        calcDepth(root->right, d + 1);
	}
	void calcParents(TreeNode* root)
	{
		if (!root) return;
		if (root->left)
		{
			parents[root->left] = root;
			calcParents(root->left);
		}
		if (root->right)
		{
			parents[root->right] = root;
			calcParents(root->right);
		}
	}
	TreeNode* lcaDeepestLeaves(TreeNode* root) {
		depth.clear();
		parents.clear();
		parents[root] = nullptr;
		calcDepth(root);
		calcParents(root);
		int maxDepth = 0;
		for (auto d : depth)
			maxDepth = max(maxDepth, d.second);
		vector<TreeNode*> nodes;
		for (auto d : depth)
			if (d.second == maxDepth)
				nodes.push_back(d.first);
		while (true)
		{
			bool flag = true;
			for(int i = 1; i < nodes.size(); ++i)
				if (nodes[i - 1] != nodes[i])
				{
					flag = false; break;
				}
			if (flag)
				break;
			for (TreeNode*& node : nodes)
				node = parents[node];
		}
		return nodes[0];
	}
	map<TreeNode*, int> depth;
	map<TreeNode*, TreeNode*> parents;
};