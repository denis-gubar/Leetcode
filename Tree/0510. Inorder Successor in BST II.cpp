class Solution {
public:
	Node* inorderSuccessor(Node* node, bool checkLeft = false) {
		if (!node) return nullptr;
		Node* result = nullptr;
		if (checkLeft)
		{
			result = inorderSuccessor(node->left, true);
			if (!result)
				return node;
			return result;
		}
		result = inorderSuccessor(node->right, true);
		if (!result)
		{
			while (node->parent)
			{
				if (node->parent->left == node)
					return node->parent;
				node = node->parent;
			}
			return nullptr;
		}
		return result;
	}
};