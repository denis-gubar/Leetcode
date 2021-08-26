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
	ListNode* reverseList(ListNode* head)
	{
		ListNode* result = nullptr;
		ListNode* node = head;
		while (node)
		{
			ListNode* nextNode = node->next;
			node->next = result;
			result = node;
			node = nextNode;
		}
		return result;
	}
	void reorderList(ListNode* head) {
		if (!head) return;
		ListNode start(0);
		start.next = head;
		ListNode* leftTail = &start;
		ListNode* rightTail = &start;
		while (rightTail && rightTail->next)
		{
			leftTail = leftTail->next;
			rightTail = rightTail->next->next;
		}
		rightTail = reverseList(leftTail->next);
		leftTail->next = nullptr;
		leftTail = head;
		while (rightTail)
		{
			ListNode* rightNext = rightTail->next;
			ListNode* leftNext = leftTail->next;
			rightTail->next = leftTail->next;
			leftTail->next = rightTail;
			rightTail = rightNext;
			leftTail = leftNext;
		}
	}
};