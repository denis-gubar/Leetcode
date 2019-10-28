class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int sum = l1->val + l2->val;
		int extra = sum / 10;
		sum %= 10;
		ListNode* result = new ListNode(sum);
		ListNode* node = result;
		while (l1->next || l2->next || extra)
		{
			sum = extra;
			if (l1->next)
			{
				l1 = l1->next;
				sum += l1->val;
			}
			if (l2->next)
			{
				l2 = l2->next;
				sum += l2->val;
			}
			extra = sum / 10;
			sum %= 10;
			ListNode* currentNode = new ListNode(sum);
			node->next = currentNode;
			node = currentNode;			
		}
		return result;
	}
};