/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* intersect(Node* quadTree1, Node* quadTree2) {
        Node* result = new Node();
        if (quadTree1->isLeaf && quadTree2->isLeaf)
            result->isLeaf = true, result->val = quadTree1->val | quadTree2->val;
        else if (!quadTree1->isLeaf && !quadTree2->isLeaf)
        {
            result->topLeft = intersect(quadTree1->topLeft, quadTree2->topLeft),
            result->topRight = intersect(quadTree1->topRight, quadTree2->topRight),
            result->bottomLeft = intersect(quadTree1->bottomLeft, quadTree2->bottomLeft),
            result->bottomRight = intersect(quadTree1->bottomRight, quadTree2->bottomRight);
            if (result->topLeft->isLeaf &&
                result->topRight->isLeaf &&
                result->bottomLeft->isLeaf &&
                result->bottomRight->isLeaf &&
                (result->topLeft->val + result->topRight->val + result->bottomLeft->val + result->bottomRight->val) % 4 == 0
            )
                result = new Node(result->topLeft->val, true);
        }
        else if (quadTree1->isLeaf && quadTree1->val || 
                quadTree2->isLeaf && quadTree2->val)
            result = new Node(true, true);
        else if (quadTree1->isLeaf)
            result = quadTree2;
        else
            result = quadTree1;
        return result;
    }
};
