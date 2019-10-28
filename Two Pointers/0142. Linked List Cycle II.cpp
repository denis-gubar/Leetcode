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
	ListNode *detectCycle(ListNode *head) {
		ListNode* fast = head;
		ListNode* slow = head;
		int length = 0;
		int limit = 1;
		while (fast)
		{
			fast = fast->next;
			++length;
    		if (!fast)
	    		return nullptr;
			if (fast == slow)
				break;
			else if (length == limit)
			{
				length = 0; limit <<= 1;
				slow = fast;
			}
		}
		fast = head;
		slow = head;
		for (int i = 0; i < length; ++i)
			fast = fast->next;
		while (fast != slow)
		{
			fast = fast->next;
			slow = slow->next;
		}
		return fast;
	}
};