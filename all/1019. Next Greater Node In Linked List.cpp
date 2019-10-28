/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	vector<int> nextLargerNodes(ListNode* head) {
		vector<int> result;
		stack<pair<int, int>> S;
		for (ListNode* node = head; node != nullptr; node = node->next)
		{
			while (!S.empty() && S.top().first < node->val)
			{
				pair<int, int> p = S.top(); S.pop();
				result[p.second] = node->val;
			}
			S.push({ node->val, static_cast<int>(result.size()) });
			result.push_back(0);
		}		
		return result;
	}
};