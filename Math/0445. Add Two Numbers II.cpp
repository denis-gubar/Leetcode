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
	ListNode* reverse(ListNode* head) {
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
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* h1 = reverse(l1);
		ListNode* h2 = reverse(l2);
		ListNode* start = new ListNode(0);
		ListNode* h = start;
		int extra = 0;
		while (h1 || h2 || extra)
		{
			if (h1)
				extra += h1->val, h1 = h1->next;
			if (h2)
				extra += h2->val, h2 = h2->next;
			h->next = new ListNode(extra % 10);
			extra /= 10;
			h = h->next;
		}
		ListNode* result = reverse(start->next);
		delete start;
		return result;
	}
};