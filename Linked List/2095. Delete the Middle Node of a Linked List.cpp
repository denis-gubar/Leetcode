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
	ListNode* deleteMiddle(ListNode* head) {
		ListNode* result = nullptr;
		vector<int> A;
		while (head)
		{
			A.push_back(head->val);
			head = head->next;
		}
		A.erase(A.begin() + A.size() / 2);
		if (!A.empty())
		{
			result = new ListNode(A[0]);
			ListNode* node = result;
			for (int i = 1; i < A.size(); ++i)
			{
				node->next = new ListNode(A[i]);
				node = node->next;
				node->next = nullptr;
			}
		}
		return result;
	}
};