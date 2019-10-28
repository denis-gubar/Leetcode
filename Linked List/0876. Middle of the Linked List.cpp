class Solution {
public:
	ListNode * middleNode(ListNode* head) {
		ListNode* fastNode = head;
		ListNode* slowNode = head;
		while (fastNode != nullptr && fastNode->next != nullptr)
		{
			fastNode = fastNode->next;
			fastNode = fastNode->next;
			slowNode = slowNode->next;
		}
		return slowNode;
	}
};