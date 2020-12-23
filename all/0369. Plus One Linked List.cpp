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
	vector<int> plusOne(vector<int> digits)
	{
		reverse(digits.begin(), digits.end());
		int n = digits.size();
		int i = 0;
		for (; i < n && digits[i] == 9; ++i)
			digits[i] = 0;
		if (i < n)
			++digits[i];
		else
			digits.push_back(1);
		reverse(digits.begin(), digits.end());
		return digits;
	}
	vector<int> decode(ListNode* head)
	{
		if (!head) return { 0 };
		vector<int> result;
		while (head)
		{
			result.push_back(head->val);
			head = head->next;
		}
		return result;
	}
	ListNode* encode(vector<int> const& digits)
	{
		ListNode* node = new ListNode(digits[0]);
		ListNode* result = node;
		for (int i = 1; i < digits.size(); ++i)
		{
			node->next = new ListNode(digits[i]);
			node = node->next;
		}
		return result;
	}
	ListNode* plusOne(ListNode* head) {
		return encode(plusOne(decode(head)));
	}
};