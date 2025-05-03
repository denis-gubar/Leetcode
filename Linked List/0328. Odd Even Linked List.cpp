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
    ListNode* oddEvenList(ListNode* head) {
        ListNode odd, even;
        ListNode* oddNode = &odd;
        ListNode* evenNode = &even;
        for (ListNode* node = head; node != nullptr; )
        {
            oddNode->next = node, oddNode = oddNode->next;
            node = node->next;
            oddNode->next = nullptr;
            if (node == nullptr)
                break;
            evenNode->next = node, evenNode = evenNode->next;
            node = node->next;
            evenNode->next = nullptr;
        }
        oddNode->next = even.next;
        return odd.next;
    }
};
