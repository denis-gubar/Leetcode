/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* start = new ListNode(0);
        start->next = head;
        ListNode* node = start;
        while (node->next)
        {
            if (node->next->val == val)
            {
                ListNode* temp = node->next;
                node->next = temp->next;
                delete temp;
            }
            else
                node = node->next;
        }
        ListNode* result = start->next;
        delete start;
        return result;
    }
};