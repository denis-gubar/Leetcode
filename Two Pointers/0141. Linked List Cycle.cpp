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
	bool hasCycle(ListNode *head) {
		ListNode* slow = head, *fast = head;
		int limit = 1;
		int currentPathLength = 0;
		while (fast)
		{
			fast = fast->next;
			if (fast == slow)
				return true;
			if (limit == ++currentPathLength)
				limit <<= 1, currentPathLength = 0, slow = fast;			
		}
		return false;
	}
};