class Solution {
public:
	struct BinaryTrie
	{
		BinaryTrie() : left(nullptr), right(nullptr) {}
		void add(int x)
		{
			BinaryTrie* node = this;
			for (int k = 20; k >= 0; --k)
			{
				if (x & (1 << k))
				{
					if (!node->right)
						node->right = new BinaryTrie;
					node = node->right;
				}
				else
				{
					if (!node->left)
						node->left = new BinaryTrie;
					node = node->left;
				}
			}
		}
		BinaryTrie* left;
		BinaryTrie* right;
	};
	long long maxProduct(vector<int>& nums) {
        long long result = 0;
        int const N = nums.size();
		BinaryTrie Trie;
		Trie.add(0);

		int best = 0;
		auto dfs = [&best](this const auto& self, BinaryTrie* node, int value, int k, int x) -> bool
			{
				if (k < 0)
				{
					best = max(best, value);
					return true;
				}
				if (x & (1 << k))
				{
					if (!node->left)
						return false;
					return self(node->left, value, k - 1, x);
				}
				if (node->right && self(node->right, value | (1 << k), k - 1, x))
					return true;
				if (!node->left)
					return false;
				return self(node->left, value, k - 1, x);
			};
		for (int x : nums)
		{
			best = 0;
			dfs(&Trie, 0, 20, x);
			result = max(result, 1LL * x * best);
			Trie.add(x);
		}
        return result;
    }
};
