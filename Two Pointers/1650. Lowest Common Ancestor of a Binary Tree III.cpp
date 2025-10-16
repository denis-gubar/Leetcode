/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        unordered_set<Node*> S;
        for(Node* node = p; node != nullptr; node = node->parent)
            S.insert(node);
        for(Node* node = q; node != nullptr; node = node->parent)
            if (S.find(node) != S.end())
                return node;
        return nullptr;
    }
};