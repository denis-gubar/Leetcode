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
	ListNode* swapNodes(ListNode* head, int k) {
		vector<int> A;
		ListNode* node = head;
		while (node)
		{
			A.push_back(node->val);
			node = node->next;
		}
		swap(A[k - 1], A[A.size() - k]);
		ListNode* result = new ListNode(A[0]);
		node = result;
		for (int i = 1; i < A.size(); ++i)
		{
			node->next = new ListNode(A[i]);
			node = node->next;
		}
		return result;
	}
};