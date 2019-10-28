class Solution {
public:
	void findParents(TreeNode* root)
	{
		if (!root) return;
		if (root->left)
			parents[root->left->val] = root;
		if (root->right)
			parents[root->right->val] = root;
		findParents(root->left);
		findParents(root->right);
	}
	void find(TreeNode* root)
	{
		if (!root) return;
		nodes[root->val] = root;
		find(root->left);
		find(root->right);
	}
	int calc(TreeNode* root)
	{
		if (!root)
			return 0;
		return 1 + calc(root->left) + calc(root->right);
	}
	bool btreeGameWinningMove(TreeNode* root, int n, int x) {
		nodes = vector<TreeNode*>(n + 1);
		parents = vector<TreeNode*>(n + 1, nullptr);
		findParents(root);
		find(root);
		int L = 0;
		int v = x;
		while (parents[v])
			++L, v = parents[v]->val;
		if (L)
		{
			int first = L / 2 + calc(nodes[x]);
			int second = n - first;
			if (second > first)
				return true;
		}
		if (nodes[x]->left)
		{
			int second = calc(nodes[x]->left);
			int first = n - second;
			if (second > first)
				return true;
		}
		if (nodes[x]->right)
		{
			int second = calc(nodes[x]->right);
			int first = n - second;
			if (second > first)
				return true;
		}
		return false;
	}
	vector<TreeNode*> nodes, parents;
};