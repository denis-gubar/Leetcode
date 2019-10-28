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
	int size(ListNode* head)
	{
		int result = 0;
		while (head)
		{
			head = head->next;
			++result;
		}
		return result;
	}
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		int sizeA = size(headA);
		int sizeB = size(headB);
		ListNode* nodeA = headA;
		ListNode* nodeB = headB;
		while (sizeA < sizeB)
		{
			nodeB = nodeB->next;
			--sizeB;
		}
		while (sizeA > sizeB)
		{
			nodeA = nodeA->next;
			--sizeA;
		}
		while (true)
		{
			if (nodeA == nodeB)
				return nodeA;
			nodeA = nodeA->next;
			nodeB = nodeB->next;
		}
	}
};