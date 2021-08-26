class CBTInserter {
public:
	void calcQ()
	{		
		q.push(root);
		q.push(root);
		nodes += 2;
		while (true)
		{
			TreeNode* node = q.front();
			if (nodes % 2 == 0)
				if (node->left)
				{
					q.push(node->left);
					q.push(node->left);
					nodes += 2;
				}
				else
					break;
			else
				if (node->right)
				{
					q.push(node->right);
					q.push(node->right);
					nodes += 2;
				}
				else
					break;
			q.pop();
			--nodes;
		}
	}
	CBTInserter(TreeNode* root): root(root), nodes(0) {		
		calcQ();
	}

	int insert(int v) {
		TreeNode* node = q.front();
		q.pop();
		--nodes;
		TreeNode* newNode = new TreeNode(v);
		if (nodes % 2)
			node->left = newNode;
		else
			node->right = newNode;
		q.push(newNode);
		q.push(newNode);
		nodes += 2;
		return node->val;
	}

	TreeNode* get_root() {
		return root;
	}
	TreeNode* root;
	map<TreeNode*, TreeNode*> parents;
	int nodes;
	queue<TreeNode*> q;
};