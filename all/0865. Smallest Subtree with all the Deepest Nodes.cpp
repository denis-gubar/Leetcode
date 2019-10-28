class Solution {
public:
	map<TreeNode*, TreeNode*> parents;
	map<TreeNode*, int> depth;
	map<TreeNode*, bool> isLeft;
	map<TreeNode*, bool> isAdded;
	map<TreeNode*, TreeNode*> newTree;
	void calc(TreeNode* node, int d)
	{
		if (node)
		{
			isAdded[node] = false;
			depth[node] = d;
			if (node->left)
			{
				parents[node->left] = node;
				isLeft[node->left] = true;
				calc(node->left, d + 1);
			}
			if (node->right)
			{
				parents[node->right] = node;
				isLeft[node->right] = false;
				calc(node->right, d + 1);
			}
		}
	}
	TreeNode* resultNode;
	void add(TreeNode* node)
	{
		if (isAdded[node])
			return;
		isAdded[node] = true;
		if (resultNode == nullptr)
			resultNode = node;
		else
		{
			int a = depth[resultNode];
			while (depth[node] > depth[resultNode])
			{
				isAdded[node] = true;
				node = parents[node];
			}
			while (depth[resultNode] > depth[node])
			{
				resultNode = parents[resultNode];
				isAdded[resultNode] = true;
			}
			while (resultNode != node)
			{
				node = parents[node];
				isAdded[node] = true;
				resultNode = parents[resultNode];
				isAdded[resultNode] = true;
			}
		}
	}
	TreeNode * subtreeWithAllDeepest(TreeNode* root) {
		calc(root, 0);
		resultNode = nullptr;
		int maxD = 0;
		for (auto d : depth)
		{
			maxD = max(maxD, d.second);
			newTree[d.first] = new TreeNode(d.first->val);
		}
		for (auto d : depth)
			if (d.second == maxD)
			{
				add(d.first);
			}
		return resultNode;
	}
};