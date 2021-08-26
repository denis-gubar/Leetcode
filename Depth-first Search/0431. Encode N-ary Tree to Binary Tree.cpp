/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
public:
	// Encodes an n-ary tree to a binary tree.
	TreeNode* encode(Node* root) {
		if (!root) return nullptr;
		TreeNode* result = new TreeNode(root->val);
		result->left = new TreeNode(root->children.size());
		TreeNode* parent = result->left;
		for (int i = 0; i < root->children.size(); ++i)
		{
			parent->right = encode(root->children[i]);
			parent = parent->right;
		}
		return result;
	}

	// Decodes your binary tree to an n-ary tree.
	Node* decode(TreeNode* root) {
		if (!root) return nullptr;
		Node* result = new Node(root->val);
		TreeNode* parent = root->left;
		for (int i = 0; i < root->left->val; ++i)
		{
			result->children.push_back(decode(parent->right));
			parent = parent->right;
		}
		return result;
	}
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(root));