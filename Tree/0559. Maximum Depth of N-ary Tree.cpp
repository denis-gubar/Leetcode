/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    int maxDepth(Node* root) {
        int result = 0;
        if (root)
        {
            int current = 0;
            for(Node* child: root->children)
                current = max(current, maxDepth(child));
            result = current + 1;
        }
        return result;
    }
};