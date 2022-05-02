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
    int pairSum(ListNode* head) {
        int result = 0;
        vector<int> A;
        while (head)
        {
            A.push_back(head->val);
            head = head->next;
        }
        int N = A.size();
        for (int a = 0, b = N - 1; a < b; ++a, --b)
            result = max(result, A[a] + A[b]);
        return result;
    }
};
