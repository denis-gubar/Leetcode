/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* start = new ListNode(0);
		start->next = head;
		ListNode* first = start;
		ListNode* second = start;
		for (int i = 0; i < n; ++i)
			first = first->next;
		while (first->next)
		{
			first = first->next;
			second = second->next;
		}
		ListNode* temp = second->next;
		second->next = second->next->next;
		delete temp;
		ListNode* result = start->next;
		delete start;
		return result;
	}
};