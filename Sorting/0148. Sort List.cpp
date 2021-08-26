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
	ListNode* merge( ListNode* l1, ListNode* l2 ) {
		ListNode* result = new ListNode( -999 );
		ListNode* node = result;
		while (l1 || l2)
			if (l1 && l2 && l1->val == l2->val)
			{
				node->next = l1;
				node = l1;
				l1 = l1->next;
				node->next = l2;
				node = l2;
				l2 = l2->next;
			}
			else if (l1 && (!l2 || l1->val < l2->val))
			{
				node->next = l1;
				node = l1;
				l1 = l1->next;
			}
			else if (l2 && (!l1 || l1->val > l2->val))
			{
				node->next = l2;
				node = l2;
				l2 = l2->next;
			}
		ListNode* temp = result;
		result = result->next;
		delete temp;
		return result;
	}
	void partitionList( ListNode* head, ListNode** a, ListNode** b )
	{
		*a = head;
		ListNode* node = head;
		ListNode* a_end = head;
		if (node)
			node = node->next;
		while (node)
		{
			node = node->next;
			if (node)
			{
				node = node->next;
				a_end = a_end->next;
			}
		}
		*b = a_end->next;
		a_end->next = nullptr;
	}
	ListNode* sortList( ListNode* head ) {
		if (!head || !head->next)
			return head;
		ListNode* a = nullptr;
		ListNode* b = nullptr;
		this->partitionList( head, &a, &b );
		a = this->sortList( a );
		b = this->sortList( b );
		ListNode* result = this->merge( a, b );
		return result;
	}
};