class Solution {
public:
	ListNode* mergeTwoLists( ListNode* l1, ListNode* l2 ) {
		ListNode* root = NULL;
		ListNode* node = NULL;
		while (l1 || l2)
		{
			if (!l2 || l1 && l1->val < l2->val)
			{
				ListNode* next = new ListNode( l1->val );
				if (node)
					node->next = next;
				else
					root = next;
				node = next;
				l1 = l1->next;
			}
			else
			{
				ListNode* next = new ListNode( l2->val );
				if (node)
					node->next = next;
				else
					root = next;
				node = next;
				l2 = l2->next;
			}
		}
		return root;
	}
};