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
    ListNode* removeNodes(ListNode* head) {
        vector<int> A, B;
        B.reserve(100'000);
        ListNode* node = head;
        while (node != nullptr)
        {
            B.push_back(node->val);
            node = node->next;
        }
        A.push_back(B.back());
        B.pop_back();
        while (!B.empty())
        {
            if (A.back() <= B.back())
                A.push_back(B.back());
            B.pop_back();
        }
        reverse(A.begin(), A.end());
        ListNode* result = new ListNode(A[0]);
        node = result;
        for (int i = 1; i < A.size(); ++i)
        {
            node->next = new ListNode(A[i]);
            node = node->next;
        }
        return result;
    }
};
