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
    static vector<string> split(const string& s, char delimeter = ' ')
    {
        vector<string> result;
        istringstream ss(s);
        for (string token; !ss.eof(); )
        {
            getline(ss, token, delimeter);
            result.push_back(token);
        }
        return result;
    }
	static TreeNode* Create(const string& s)
	{
		vector<string> Nodes{ split(s.substr(1, s.size() - 2), ',') };
		if (Nodes.empty())
			return nullptr;
		TreeNode* root = new TreeNode(stoi(Nodes[0]));
		queue<TreeNode*> Q;
		Q.push(root);
		size_t i = 1;
		while (i < Nodes.size())
		{
			TreeNode* node = Q.front(); Q.pop();
			if (Nodes[i] != "null")
			{
				node->left = new TreeNode(stoi(Nodes[i]));
				Q.push(node->left);
			}
			++i;
			if (i < Nodes.size() && Nodes[i] != "null")
			{
				node->right = new TreeNode(stoi(Nodes[i]));
				Q.push(node->right);
			}
			++i;
		}
		return root;
	}
	void collect(TreeNode* root, vector<int>& Nodes)
	{
		if (!root) return;
		collect(root->left, Nodes);
		Nodes.push_back(root->val);
		collect(root->right, Nodes);
	}
	void fill(TreeNode* root, vector<int>::iterator& it)
	{
		if (!root) return;
		fill(root->left, it);
		root->val = *it;
		++it;
		fill(root->right, it);
	}
	TreeNode* balanceBST(TreeNode* root) {
		vector<int> Nodes;
		collect(root, Nodes);
		string nodes = "[0";
		for (int i = 1; i < Nodes.size(); ++i)
			nodes += ",0";
		nodes += ']';
		TreeNode* result = Create(nodes);
        auto it = Nodes.begin();
		fill(result, it);
		return result;
	}
};