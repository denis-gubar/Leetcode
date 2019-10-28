struct BinaryTrie
{
	BinaryTrie() : left(nullptr), right(nullptr) {}
	~BinaryTrie()
	{
		if (left)
			delete left;
		if (right)
			delete right;
	}
	int add(int x)
	{
		bool exists = true;
		BinaryTrie* node = this;
		BinaryTrie* xorNode = this;
		int xorX = 0;
		for (int k = 30; k >= 0; --k)
		{
			if (x & (1 << k))
			{
				if (!node->right)
					node->right = new BinaryTrie;				
				node = node->right;
				if (xorNode)
				{
					if (xorNode->left)
						xorNode = xorNode->left;
					else
					{
						xorNode = xorNode->right;
						xorX |= 1 << k;
					}
				}
			}
			else
			{
				if (!node->left)
					node->left = new BinaryTrie;
				node = node->left;
				if (xorNode)
				{
					if (xorNode->right)
					{
						xorNode = xorNode->right;
						xorX |= 1 << k;
					}
					else 
						xorNode = xorNode->left;
				}
			}
		}
		if (xorNode)
			return x ^ xorX;
		return 0;
	}
	BinaryTrie* left;
	BinaryTrie* right;
};

class Solution {
public:
	int findMaximumXOR(vector<int>& nums) {
		int result = 0;
		BinaryTrie trie;
		for (int n : nums)
			result = max(result, trie.add(n));
		return result;
	}
};