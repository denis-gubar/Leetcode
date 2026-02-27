class Solution {
public:
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
			for (int k = 15; k >= 0; --k)
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
    int maxXor(vector<int>& nums, int K) {
        int result = *max_element(nums.begin(), nums.end());
        int const N = nums.size();
		BinaryTrie trie;
		deque<int> QA, QB;
		auto remove = [&nums, &QA, &QB](int pos)
			{
				while (!QA.empty() && QA.front() <= pos)
					QA.pop_front();
				while (!QB.empty() && QB.front() <= pos)
					QB.pop_front();
			};
		auto add = [&nums, &QA, &QB](int pos)
			{
				while (!QA.empty() && nums[QA.front()] <= nums[pos])
					QA.pop_front();
				while (!QA.empty() && nums[QA.back()] <= nums[pos])
					QA.pop_back();
				QA.push_back(pos);
				while (!QB.empty() && nums[QB.front()] >= nums[pos])
					QB.pop_front();
				while (!QB.empty() && nums[QB.back()] >= nums[pos])
					QB.pop_back();
				QB.push_back(pos);
			};
		int left = 0, right = 0;
		int xorMask = 0;
		trie.add(0);
		while (right < N)
		{
			add(right);
			bool flag = false;
			while (!QA.empty() && !QB.empty() && nums[QA.front()] - nums[QB.front()] > K)
				flag = true, remove(left), ++left;
			if (flag)
			{
				xorMask = 0;
				trie.left = trie.right = nullptr;
				trie.add(0);
				for (int i = left; i <= right; ++i)
					xorMask ^= nums[i], result = max(result, trie.add(xorMask));
			}
			else
			{
				xorMask ^= nums[right];
				result = max(result, trie.add(xorMask));
			}
			++right;
		}
		return result;
    }
};
