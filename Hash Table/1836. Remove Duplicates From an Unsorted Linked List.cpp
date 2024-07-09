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
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {
        ListNode temp(-1);
        vector<bool> visited(100'001);
        vector<bool> duplicates(100'001);
        for (ListNode* node = head; node != nullptr; node = node->next)
            if (!visited[node->val])
                visited[node->val] = true;
            else
                duplicates[node->val] = true;
        ListNode* tail = &temp;
        for (ListNode* node = head; node != nullptr; node = node->next)
            if (!duplicates[node->val])
                tail->next = new ListNode(node->val), tail = tail->next;
        return temp.next;
    }
};
