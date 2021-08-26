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
	/** @param head The linked list's head.
		Note that the head is guaranteed to be not null, so it contains at least one node. */
	Solution(ListNode* head) {
		gen.seed(rd());
		while (head)
		{
			buckets.push_back(head->val);
			head = head->next;
		}
		distribution = uniform_int_distribution<>(0, buckets.size() - 1);
	}

	/** Returns a random node's value. */
	int getRandom() {
		return buckets[distribution(gen)];
	}
	random_device rd;  //Will be used to obtain a seed for the random number engine
	mt19937 gen; //Standard mersenne_twister_engine seeded with rd()
	uniform_int_distribution<> distribution;
	vector<int> buckets;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */