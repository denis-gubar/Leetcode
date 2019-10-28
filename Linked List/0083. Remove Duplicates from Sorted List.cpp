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
		ListNode* node = head;
		while (node && node->next)
			if (node->val == node->next->val)
			{
				ListNode* temp = node->next;
				node->next = temp->next;
				delete temp;
			}
			else
				node = node->next;
		return head;
	}
};