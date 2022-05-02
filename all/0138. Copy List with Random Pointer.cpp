/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList( Node *head ) {
        if (head == nullptr)
            return nullptr;
        unordered_map<Node*, Node*> M;
        Node* node = head;
        while (node != nullptr)
        {
            M[node] = new Node( node->val );
            node = node->next;
        }
        node = head;
        while (node != nullptr)
        {
            M[node]->next = M[node->next];
            M[node]->random = M[node->random];
            node = node->next;
        }
        return M[head];
    }
};