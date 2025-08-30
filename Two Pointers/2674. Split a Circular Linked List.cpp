/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> splitCircularLinkedList(ListNode* list) {
        int N = 1;
        ListNode* node = list->next;
        while (node != list)
            node = node->next, ++N;
        vector<ListNode*> result(2);
        result[0] = node;
        for (int i = 0; i < (N - 1) / 2; ++i)
            node = node->next;
        result[1] = node->next;
        node->next = result[0];
        node = result[1];
        while (node->next != list)
            node = node->next;
        node->next = result[1];
        return result;
    }
};
