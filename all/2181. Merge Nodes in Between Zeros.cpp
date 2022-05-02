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
        vector<int> A;
        int sum = 0;
        while (head)
        {
            int x = head->val;
            if (x > 0)
                sum += x;
            else if (sum > 0)
            {
                A.push_back(sum);
                sum = 0;
            }
            head = head->next;
        }
        if (A.empty())
            return nullptr;
        ListNode* result = new ListNode(A[0]);
        ListNode* node = result;
        for (int i = 1; i < A.size(); ++i)
        {
            node->next = new ListNode(A[i]);
            node = node->next;
        }
        return result;
    }
};
