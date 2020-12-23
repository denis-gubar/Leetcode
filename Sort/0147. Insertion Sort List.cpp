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
	ListNode* insertionSortList(ListNode* head) {
		ListNode* result = nullptr;
		ListNode* start = new ListNode(0);
        start->next = nullptr;
		while (head)
		{
            ListNode* node = start;
			while (node->next != nullptr && node->next->val < head->val)
				node = node->next;
            ListNode* insertNode = new ListNode(head->val);
            insertNode->next = node->next;
            node->next = insertNode;
			head = head->next;
		}
        result = start->next;
		delete start;
		return result;
	}
};