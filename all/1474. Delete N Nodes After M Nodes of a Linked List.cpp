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
    ListNode* deleteNodes(ListNode* head, int M, int N) {
        ListNode* node = new ListNode();
        node->next = head;
        while (true)
        {
            for (int i = 0; i < M; ++i)
            {
                if (node == nullptr)
                    return head;
                node = node->next;
            }
            for (int i = 0; i < N; ++i)
            {
                if (node == nullptr || node->next == nullptr)
                    return head;
                node->next = node->next->next;
            }
        }
        return head;
    }
};
