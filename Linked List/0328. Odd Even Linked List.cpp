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
	ListNode* oddEvenList(ListNode* head) {
		ListNode* start = new ListNode(0);
		start->next = head;
		ListNode* startEven = new ListNode(0);
		ListNode* evenNode = startEven;
		ListNode* node = start;
		while (node && node->next)
		{
			node = node->next;
			if (node->next)
			{
				ListNode* nextNode = node->next;
				evenNode->next = nextNode;
				evenNode = nextNode;
				node->next = nextNode->next;
				nextNode->next = nullptr;
			}
		}
		node->next = startEven->next;
		ListNode* result = start->next;
		delete start;
		delete startEven;
		return result;
	}
};