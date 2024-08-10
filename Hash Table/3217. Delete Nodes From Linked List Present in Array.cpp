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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> S(nums.begin(), nums.end());
        ListNode temp(-1);
        ListNode* node = &temp;
        while (head)
        {
            if (S.find(head->val) == S.end())
                node->next = new ListNode(head->val), node = node->next;
            head = head->next;
        }
        return temp.next;
    }
};
