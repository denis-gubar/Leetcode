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

class Solution {
public:
	Node* findRoot(vector<Node*> tree) {
		Node* result = nullptr;
		int id = 0;
		for (auto node : tree)
		{
			id ^= node->val;
			for (auto child : node->children)
				id ^= child->val;
		}
		for (auto node : tree)
			if (node->val == id)
				result = node;
		return result;
	}
};