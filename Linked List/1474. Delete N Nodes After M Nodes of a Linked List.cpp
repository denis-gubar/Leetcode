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
	ListNode* deleteNodes(ListNode* head, int m, int n) {
		int k = 0;
		ListNode* node = head;
		ListNode* last = nullptr;
		while (node)
		{
			ListNode* next = node->next;
			if (k % (m + n) == m - 1)
			{
                if (last && m == 1)
                    last->next = node;
				last = node;
				last->next = nullptr;
			}
			else if (last && k % (m + n) == 0)
				last->next = node;
			else if (k % (m + n) >= m)
				delete node;
			node = next;
			++k;
		}
		return head;
	}
};