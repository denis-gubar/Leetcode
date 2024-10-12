/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    bool isFirst;
    Node* result;
    Node* node;
    void calc(Node* root)
    {
        if (!root) return;
        calc(root->left);
        if (isFirst)
        {
            isFirst = false;
            result = root;
            node = result;
        }
        else
        {
            root->left = node;
            node = root;
        }
        calc(root->right);
    }
    Node* treeToDoublyList(Node* root) {
        if (!root) return root;
        isFirst = true;
        calc(root);
        result->left = node;
        Node* nextNode = result;
        while(true)
        {
            node->right = nextNode;
            nextNode = node;
            node = node->left;
            if (nextNode == result)
                break;
        }
        return result;
    }
};
