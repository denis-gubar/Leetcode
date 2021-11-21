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
	vector<int> nodesBetweenCriticalPoints(ListNode* head) {
		vector<int> result = { -1, -1 };
		vector<int>	A, P;
		while (head)
		{
			A.push_back(head->val);
			head = head->next;
		}
		int N = A.size();
		for (int i = 1; i < N - 1; ++i)
			if (A[i] > A[i - 1] && A[i] > A[i + 1] || A[i] < A[i - 1] && A[i] < A[i + 1])
				P.push_back(i);
		N = P.size();
		if (N > 1)
		{
			result = { P.back() - P[0], P.back() - P[0] };
			for (int i = 1; i < N; ++i)
				result[0] = min(result[0], P[i] - P[i - 1]);
		}
		return result;
	}
};