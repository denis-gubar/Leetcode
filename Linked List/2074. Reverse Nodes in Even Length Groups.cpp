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
	ListNode* reverseEvenLengthGroups(ListNode* head) {
		vector<int> A;
		while (head)
		{
			A.push_back(head->val);
			head = head->next;
		}
		int N = A.size();
		int K = 1;
		int pos = 0;
		while (pos < N)
		{			
			int last = min(N, K + pos);
            ++K;
			if ((last - pos) % 2 == 0)
				reverse(A.begin() + pos, A.begin() + last);
			pos += K;
			pos = last;
		}
		ListNode* result = new ListNode(A[0]);
		ListNode* node = result;
		for (int i = 1; i < A.size(); ++i)
		{
			node->next = new ListNode(A[i]);
			node = node->next;
		}
		return result;
	}
};