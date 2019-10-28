/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode* copyRandomList( RandomListNode *head ) {
        if (head == nullptr)
            return nullptr;
        map<RandomListNode*, RandomListNode*> M;
        RandomListNode* node = head;
        while (node != nullptr)
        {
            M[node] = new RandomListNode( node->label );
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