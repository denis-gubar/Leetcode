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
	ListNode* removeZeroSumSublists(ListNode* head) {
		ListNode* result = new ListNode(0);
		result->next = head;
		bool flag = true;
		while (flag)
		{
			flag = false;
			vector<int> sum;
			vector<ListNode*> nodes;
			nodes.push_back(result);
			ListNode* node = result->next;
			while (node)
			{
				nodes.push_back(node);
				sum.push_back(0);
				for (int i = 0; i < sum.size(); ++i)
				{
					sum[i] += node->val;
					if (!sum[i])
					{
						nodes[i]->next = node->next;
						flag = true;
						break;
					}
				}
				if (flag)
					break;
				node = node->next;
			}
		}
		return result->next;
	}
};