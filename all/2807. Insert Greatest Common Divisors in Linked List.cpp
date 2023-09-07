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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
		vector<int> A, B;
		ListNode* node = head;
		while (node)
		{
			A.push_back(node->val);
			node = node->next;
		}
		int N = A.size();
		B.push_back(A[0]);
		for (int i = 1; i < N; ++i)
		{
			B.push_back(gcd(A[i - 1], A[i]));
			B.push_back(A[i]);
		}
		ListNode start(0);
		node = &start;
		for (int i = 0; i < B.size(); ++i)
		{
			node->next = new ListNode(B[i]);
			node = node->next;
		}
		return start.next;
    }
};
