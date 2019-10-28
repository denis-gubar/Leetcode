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
	ListNode* reverseList(ListNode* head) {
		ListNode* start = new ListNode(0);
		ListNode* node = head;
		while (node)
		{
			ListNode* nextNode = node->next;
			node->next = start->next;
			start->next = node;
			node = nextNode;
		}
		ListNode* result = start->next;
		delete start;
		return result;
	}
};