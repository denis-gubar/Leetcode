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
    ListNode* doubleIt(ListNode* head) {
		head = reverseList(head);
		return reverseList(addTwoNumbers(head, head));
    }
};
