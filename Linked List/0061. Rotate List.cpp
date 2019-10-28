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
	ListNode* rotateRight(ListNode* head, int k) {
		if (!head)
			return head;
		ListNode* start = new ListNode(0);
		start->next = head;
		ListNode* node = start;
		int listLength = 0;
		while (node->next)
		{
			node = node->next;
			++listLength;
		}
		node = start;
		k = (listLength - k % listLength) % listLength;
		ListNode* result = start;
		bool endFound = false;
		for (int i = 0; (i < k || !endFound) && k; ++i)
		{
			if (node->next)
				node = node->next;
			else
			{
				endFound = true;
				node->next = start->next;
				node = start->next;
			}
			if (i + 1 == k)
				result = node;
		}
		node = result;
		result = result->next;
		node->next = nullptr;
		delete start;
		return result;
	}
};