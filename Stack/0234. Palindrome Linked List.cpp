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
	ListNode* reverseList(ListNode* head)
	{
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
	bool isPalindrome(ListNode* head) {
		if (!head || !head->next)
			return true;
		ListNode* start = new ListNode(0);
		start->next = head;
		ListNode* fast = start, *slow = start;
		while (fast && fast->next)
		{
			fast = fast->next;
			fast = fast->next;
			slow = slow->next;
		}
		ListNode* center = reverseList(slow->next);
		slow->next = center;
		ListNode* left = start->next;
		ListNode* right = center;
		bool result = true;
		while (result && right)
		{
			if (left->val != right->val)
				result = false;
			left = left->next;
			right = right->next;
		}
		slow->next = reverseList(center);
		delete start;
		return result;
	}
};