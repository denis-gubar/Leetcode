class Solution {
public:
	ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
		ListNode* node = list1;
		for (int i = 1; i < a; ++i)
			node = node->next;
		ListNode* start = node;
		for (int i = a - 1; i < b; ++i)
			node = node->next;
		ListNode* finish = node;
		node = list2;
		while (node->next)
			node = node->next;
		start->next = list2;
		node->next = finish->next;
		return list1;
	}
};