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
	ListNode* reverseBetween(ListNode* head, int left, int right) {
		ListNode temp(0);
		ListNode* beforeResult = &temp;
		beforeResult->next = head;
		ListNode* before = beforeResult;
		for (int i = 1; i < left; ++i)
			before = before->next;
		ListNode* node = before->next;
		ListNode* leftNode = node;
		for (int i = left; i <= right; ++i)
		{
			ListNode* nextNode = node->next;
			node->next = before->next;
			before->next = node;
			node = nextNode;
		}
		leftNode->next = node;
		return beforeResult->next;
	}
};