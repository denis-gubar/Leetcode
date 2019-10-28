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
	ListNode* deleteDuplicates(ListNode* head) {
		if (!head)
			return head;
		ListNode* start = new ListNode(head->val - 1);
		start->next = head;
		ListNode* node = start;
		while (node->next && node->next->next)
		{
			bool isDuplicate = false;
			while (node->next->next && node->next->val == node->next->next->val)
			{
				ListNode* temp = node->next;
				node->next = node->next->next;
				delete temp;
				isDuplicate = true;
			}			
			if (isDuplicate)
			{
				ListNode* temp = node->next;
				node->next = node->next->next;
				delete temp;
				continue;
			}
			node = node->next;
		}
		ListNode* result = start->next;
		delete start;
		return result;
	}
};