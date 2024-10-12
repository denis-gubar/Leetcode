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
    ListNode* reverseList(ListNode* head) {
        ListNode* result = nullptr;
        ListNode* node = head;
        while (node)
        {
            ListNode* nextNode = node->next;
            node->next = result;
            result = node;
            node = nextNode;
        }
        return result;
    }
    ListNode* sortLinkedList(ListNode* head) {
        ListNode result;
        ListNode negative, positiv;
        ListNode* N = &negative;
        ListNode* P = &positiv;
        for (ListNode* node = head; node != nullptr; )
        {
            if (node->val >= 0)
                P->next = node, P = node;
            else
                N->next = node, N = node;
            ListNode* nextNode = node->next;
            node->next = nullptr;
            node = nextNode;
        }
        result.next = reverseList(negative.next);
        ListNode* node = result.next;
        while (node != nullptr && node->next != nullptr)
            node = node->next;
        if (node)
            node->next = positiv.next;
        else
            result.next = positiv.next;
        return result.next;
    }
};
