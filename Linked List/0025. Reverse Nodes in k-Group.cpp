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
	ListNode* reverseKGroup(ListNode* head, int k) {
		vector<int> A;
		ListNode* node = head;
		while (node)
		{
			A.push_back(node->val);
			node = node->next;
		}
		int N = A.size();
		for (int i = 0; i + k <= N; i += k)
			reverse(A.begin() + i, A.begin() + i + k);
		ListNode start(0);
		node = &start;
		for (int i = 0; i < N; ++i)
		{
			node->next = new ListNode(A[i]);
			node = node->next;
		}
		return start.next;
	}
};