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
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		auto comparator = [](ListNode* a, ListNode* b) -> bool
		{
			return a && (!b || a->val > b->val);
		};

		ListNode* start = new ListNode(0);
		ListNode* node = start;
		lists.erase(remove(lists.begin(), lists.end(), nullptr), lists.end());
		make_heap(lists.begin(), lists.end(), comparator);
		while (!lists.empty())
		{
			pop_heap(lists.begin(), lists.end(), comparator);
			ListNode* minNode = lists.back();
			if (lists.back()->next)
			{
				lists.back() = lists.back()->next;
				push_heap(lists.begin(), lists.end(), comparator);
			}
			else
				lists.pop_back();
			node->next = minNode;
			node = node->next;
		}
		ListNode* result = start->next;
		delete start;
		return result;
	}
};