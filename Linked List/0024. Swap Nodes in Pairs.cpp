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
	ListNode* swapPairs(ListNode* head) {
		ListNode* start = new ListNode(0);
		start->next = head;
		ListNode* node = start;		
		while(node->next && node->next->next)
		{
			ListNode* nodeA = node->next;
			ListNode* nodeB = nodeA->next;
			nodeA->next = nodeB->next;
			nodeB->next = nodeA;
			node->next = nodeB;
			node = nodeA;
		}
		ListNode* result = start->next;
		delete start;
		return result;
	}
};