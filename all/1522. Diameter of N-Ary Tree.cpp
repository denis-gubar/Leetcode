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
    int calc(Node* root, int& result)
	{
		if (!root) return 0;
        vector<int> current{1, 1};
        for (Node* child : root->children)
		    current.push_back(1 + calc(child, result));
        sort(current.begin(), current.end());
        result = max(result, current[current.size() - 2] + current.back() - 2);
		return current.back();
	}
    int diameter(Node* root) {
        int result = 0;
		calc(root, result);
		return result;
    }
};