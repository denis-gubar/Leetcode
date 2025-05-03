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
        while (head != nullptr)
        {
            ListNode* next = head->next;
            head->next = result;
            result = head;
            head = next;
        }
        return result;
    }
    int pairSum(ListNode* head) {
        int result = 0;
        ListNode* slow = head;
        ListNode* fast = head;
        while (true)
        {
            fast = fast->next->next;
            if (fast == nullptr)
                break;
            slow = slow->next;
        }
        slow->next = reverseList(slow->next);
        slow = slow->next;
        fast = head;
        while (slow != nullptr)
        {
            result = max(result, fast->val + slow->val);
            fast = fast->next;
            slow = slow->next;
        }
        return result;
    }
};
