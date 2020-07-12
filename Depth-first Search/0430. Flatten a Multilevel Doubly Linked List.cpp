/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
	pair<Node*, Node*> calc(Node* head)
	{
		Node* node = head;
		Node* last = head;
		while (node)
		{
			Node* nextNode = node->next;
			if (node->child)
			{
				auto [childHead, childLast] = calc(node->child);
				childHead->prev = node;
				node->next = childHead;
				childLast->next = nextNode;
				if (nextNode)
					nextNode->prev = childLast;
				node->child = nullptr;
                last = childLast;
			}
            else
                last = node;
			node = nextNode;
		}
		return { head, last };
	}
	Node* flatten(Node* head) {
		return calc(head).first;
	}
};