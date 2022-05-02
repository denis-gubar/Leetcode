/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
	Node *clone(Node *node) {
		if (!node)
			return nullptr;
		if (visited.find(node->val) != visited.end())
			return visited[node->val];
		Node* root = new Node(node->val);
		visited[node->val] = root;
		for (auto neighbor : node->neighbors)
			root->neighbors.push_back(clone(neighbor));
		return root;
	}
	Node *cloneGraph(Node *node) {
		visited.clear();
		return clone(node);
	}
	unordered_map<int, Node*> visited;
};