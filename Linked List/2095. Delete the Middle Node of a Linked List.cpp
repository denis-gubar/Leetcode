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
    ListNode* deleteMiddle(ListNode* head) {
        if (head->next == nullptr)
            return nullptr;
        ListNode* temp = new ListNode;
        temp->next = head;
        ListNode* node = head;
        while (node != nullptr && node->next != nullptr)
        {
            node = node->next->next;
            temp = temp->next;
        }
        temp->next = temp->next->next;
        return head;
    }
};
