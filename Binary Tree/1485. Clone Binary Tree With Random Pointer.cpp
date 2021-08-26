/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     Node *left;
 *     Node *right;
 *     Node *random;
 *     Node() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x, Node *left, Node *right, Node *random) : val(x), left(left), right(right), random(random) {}
 * };
 */

class Solution {
public:
	NodeCopy* mainCopy(Node* root, unordered_map<Node*, NodeCopy*>& M)
	{
		if (!root) return nullptr;
		M[root] = new NodeCopy(root->val);
		M[root]->left = mainCopy(root->left, M);
		M[root]->right = mainCopy(root->right, M);
		return M[root];
	}
	void randomCopy(Node* root, unordered_map<Node*, NodeCopy*>& M)
	{
		if (!root) return;
		M[root]->random = M[root->random];
		randomCopy(root->left, M);
		randomCopy(root->right, M);
	}
	NodeCopy* copyRandomBinaryTree(Node* root) {
		unordered_map<Node*, NodeCopy*> M;
		NodeCopy* result = mainCopy(root, M);
		randomCopy(root, M);
		return result;
	}
};