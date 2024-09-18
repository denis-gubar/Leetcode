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
    ListNode* mergeNodes(ListNode* head) {
        ListNode temp(-1);
        ListNode* node = &temp;
        ListNode* left = head;
        while (true)
        {
            ListNode* right = left->next;
            if (!right)
                break;
            int total = right->val;
            while (right->val > 0)
                right = right->next, total += right->val;
            node->next = new ListNode(total);
            node = node->next;
            left = right;
        }
        return temp.next;
    }
};
