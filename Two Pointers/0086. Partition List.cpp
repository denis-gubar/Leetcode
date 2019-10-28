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
	ListNode* partition(ListNode* head, int x) {
		ListNode* startLo = new ListNode(0);
		ListNode* startHi = new ListNode(0);
		ListNode* nodeLo = startLo;
		ListNode* nodeHi = startHi;
		ListNode* node = head;
		while (node)
		{
			if (node->val < x)
			{
				nodeLo->next = node;
				nodeLo = node;
			}
			else
			{
				nodeHi->next = node;
				nodeHi = node;
			}
			node = node->next;
		}
		nodeHi->next = nullptr;
		nodeLo->next = startHi->next;
		ListNode* result = startLo->next;
		delete startLo;
		delete startHi;
		return result;
	}
};