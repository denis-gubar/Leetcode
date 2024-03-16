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
    ListNode* frequenciesOfElements(ListNode* head) {
        unordered_map<int, int> M;
        while(head)
        {
            ++M[head->val];
            head = head->next;
        }
        ListNode* result = new ListNode(-1);
        ListNode* node = result;
        for(auto [key, value] : M)
        {
            node->next = new ListNode(value);
            node = node->next;
        }
        return result->next;
    }
};