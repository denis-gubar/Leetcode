/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
	Node* connect(Node* root) {
		if (root == nullptr) return nullptr;
		if (root->left)
		{
			if (root->right)
				root->left->next = root->right;
            else
            {
                Node* next = root->next;
                while (next)
                {
                    if (next->left)
                    {
                        root->left->next = next->left;
                        break;
                    }
                    if (next->right)
                    {
                        root->left->next = next->right;
                        break;
                    }
                    next = next->next;
                }
            }
		}
		if (root->right)
		{
			Node* next = root->next;
			while (next)
			{
				if (next->left)
				{
					root->right->next = next->left;
					break;
				}
				if (next->right)
				{
					root->right->next = next->right;
					break;
				}
				next = next->next;
			}
		}		
		connect(root->right);
        connect(root->left);
		return root;
	}
};