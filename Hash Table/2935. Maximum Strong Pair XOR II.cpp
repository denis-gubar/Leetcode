class Solution {
public:
	struct BinaryTrie
	{
		BinaryTrie() : count(1), value(0), left(nullptr), right(nullptr) {}
		~BinaryTrie()
		{
			if (left)
				delete left;
			if (right)
				delete right;
		}
		void add(int x)
		{
			BinaryTrie* node = this;
			for (int k = 20; k >= 0; --k)
			{
				if (x & (1 << k))
				{
					if (!node->right)
						node->right = new BinaryTrie;
					else
						++node->right->count;
					node = node->right;
				}
				else
				{
					if (!node->left)
						node->left = new BinaryTrie;
					else
						++node->left->count;
					node = node->left;
				}
			}
			node->value = x;
		}
		void remove(int x)
		{
			BinaryTrie* node = this;
			for (int k = 20; k >= 0; --k)
			{
				if (x & (1 << k))
				{
					--node->right->count;
					node = node->right;
				}
				else
				{
					--node->left->count;
					node = node->left;
				}				
			}
		}
		int maxXOR(int x)
		{
			BinaryTrie* node = this;
			for (int k = 20; k >= 0; --k)
			{
				if (x & (1 << k))
				{
					if (!node->left || node->left->count == 0)
						node = node->right;
					else
						node = node->left;
				}
				else
				{
					if (!node->right || node->right->count == 0)
						node = node->left;
					else
						node = node->right;
				}
			}
			return x ^ node->value;
		}
		int count;
		int value;
		BinaryTrie* left;
		BinaryTrie* right;
	};
    int maximumStrongPairXor(vector<int>& nums) {
        int N = nums.size();
        int result = 0;
		sort(nums.begin(), nums.end());
		nums.resize(unique(nums.begin(), nums.end()) - nums.begin());
		BinaryTrie* BT = new BinaryTrie;
		int L = 0, R = -1;
		for (int i = 0; i < N; ++i)
		{
			int const& y = nums[i];
			while (nums[L] < y)
			{
				BT->remove(nums[L]);
				++L;
			}
			while (R < N - 1 && nums[R + 1] <= 2 * y)
			{
				++R;
				BT->add(nums[R]);
			}
			result = max(result, BT->maxXOR(y));
		}
        return result;
    }
};
