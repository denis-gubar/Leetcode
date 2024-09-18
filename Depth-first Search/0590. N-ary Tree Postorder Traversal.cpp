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
    void calc(Node* root, vector<int>& Nodes)
    {
        if (root)
        {
            for(Node* child: root->children)
                calc(child, Nodes);
            Nodes.push_back(root->val);
        }
    }
    vector<int> postorder(Node* root) {
        vector<int> result;
        calc(root, result);
        return result;
    }
};
