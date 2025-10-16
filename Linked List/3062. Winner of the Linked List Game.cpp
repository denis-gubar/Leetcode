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
    string gameResult(ListNode* head) {
        int balance = 0;
        while(head)
        {
            int delta = head->val - head->next->val;
            if (delta > 0)
                ++balance;
            if (delta < 0)
                --balance;
            head = head->next->next;
        }
        if (balance > 0)
            return "Even";
        if (balance < 0)
            return "Odd";
        return "Tie";
    }
};