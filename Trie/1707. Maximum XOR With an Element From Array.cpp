pair<size_t, size_t> Data[2'000'000];
class Solution {
public:
	struct BinaryTrie
	{
		BinaryTrie()
		{
			memset(Data, 0, sizeof(Data));
			size = 1;
		}
		void add(int x)
		{
			size_t node = 0;
			for (int k = 30; k >= 0; --k)
			{
				if (x & (1 << k))
				{
					if (!Data[node].second)
					{
						Data[node].second = size;
						++size;
					}
					node = Data[node].second;
				}
				else
				{
					if (!Data[node].first)
					{
						Data[node].first = size;
						++size;
					}
					node = Data[node].first;
				}
			}
		}
		int calc(int x, int b)
		{
			bool isB = true;
			size_t node = 0;
			int y = 0;
			int backtrack = -1;
			int backtrackK = -1;
			size_t backtrackNode = 0;
			for (int k = 30; k >= 0; --k)
			{
				bool m = (b & (1 << k)) > 0;
				bool bit = (x & (1 << k)) > 0;
				bool hasLeft = Data[node].first;
				bool hasRight = Data[node].second;
				bool step = 0;
				if (hasRight)
				{
					if (!bit || !hasLeft)
					{
						step = 1;
						if (isB && hasLeft && m)
							backtrackNode = node, backtrackK = k, backtrack = y;
					}
					if (isB && !m)
						step = 0;
				}
				if (!isB && step == 0 && !hasLeft)
					step = 1;
				isB &= m == step;
				if (step == 0 && !hasLeft)
				{
					if (backtrack < 0)
						return -1;
					isB = false;
					y = backtrack, k = backtrackK, node = backtrackNode;
				}
				if (step)
					node = Data[node].second;
				else
					node = Data[node].first;
				y |= step << k;
			}
			return x ^ y;
		}
		size_t size;
	};
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> result;
		BinaryTrie bt;
		for (int x : nums)
			bt.add(x);
		for (vector<int> const& q : queries)
		{
			int const& x = q[0];
			int const& m = q[1];
			result.push_back(bt.calc(x, m));
		}
        return result;
    }
};
