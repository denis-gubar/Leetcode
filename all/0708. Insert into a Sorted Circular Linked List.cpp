/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if (!head)
        {
            Node* result = new Node(insertVal);
            result->next = result;
            return result;
        }
        Node* newNode = new Node(insertVal);
        Node* node = head;
        Node* nextNode = node->next;
        while(node->next != head)
        {
            if (node->val == insertVal)
                break;
            if (node->val > nextNode->val && (node->val <= insertVal || nextNode->val >= insertVal))
                break;
            if (node->val <= insertVal && nextNode->val >= insertVal)
                break;
            node = nextNode;
            nextNode = node->next;
        }
        newNode->next = node->next;
        node->next = newNode;
        return head;
    }
};