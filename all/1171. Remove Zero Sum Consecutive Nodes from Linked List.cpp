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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* result = new ListNode(0);
        result->next = head;
        unordered_map<int, ListNode*> M;
        int balance = 0;
        M[balance] = result;
        while (head)
        {
            balance += head->val;
            if (M.find(balance) != M.end())
            {
                ListNode* node = M[balance];
                while (node->next != head)
                {
                    balance += node->next->val;
                    M.erase(balance);
                    node = node->next;
                }
                balance += node->next->val;
                M[balance]->next = head->next;
            }
            else
                M[balance] = head;
            head = head->next;
        }
        return result->next;
    }
};
