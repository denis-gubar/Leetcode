/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class FindElements {
public:
	void init(TreeNode* root, int x = 0)
	{
		if (!root) return;
		S.insert(x);
		init(root->left, 2 * x + 1);
		init(root->right, 2 * x + 2);
	}

	FindElements(TreeNode* root) {
		init(root);
	}

	bool find(int target) {
		return S.find(target) != S.end();
	}
	unordered_set<int> S;
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */