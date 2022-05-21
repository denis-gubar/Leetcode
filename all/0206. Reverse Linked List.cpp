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
	ListNode* reverseList(ListNode* head) {
		ListNode* result = nullptr;
		ListNode* node = head;
		while (node)
		{
			ListNode* nextNode = node->next;
			node->next = result;
			result = node;
			node = nextNode;
		}		
		return result;
	}
};