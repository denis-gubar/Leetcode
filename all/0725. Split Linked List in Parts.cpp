class Solution {
public:
	vector<ListNode*> splitListToParts(ListNode* root, int k) {
		int n = 0;
		ListNode* node = root;
		while (node)
		{
			++n;
			node = node->next;
		}
		vector<ListNode*> result(k);
		node = root;
		for (int i = 0; i < k; ++i)
		{
			int size = n / k;
			if (n % k > i)
				++size;
			result[i] = node;
			for (int j = 0; j + 1 < size; ++j)
				node = node->next;
			ListNode* lastNode = node;
			if (node)
            {
				node = node->next;            
			    lastNode->next = nullptr;
            }
		}
		return result;
	}
};