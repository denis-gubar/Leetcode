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
	int getDecimalValue(ListNode* head, int result = 0) {
		if (!head) return result;
		return getDecimalValue(head->next, 2 * result + head->val);
	}
};
