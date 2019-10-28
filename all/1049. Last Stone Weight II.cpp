class Solution {
public:
	int lastStoneWeightII(vector<int>& stones) {
		int total = accumulate(stones.begin(), stones.end(), 0);
		int result = total;
		vector<int> F(total + 1);
		F[0] = 1;
		sort(stones.begin(), stones.end());
		for (int stone : stones)
			for (int i = total - stone; i >= 0; --i)
				if (F[i])
					F[i + stone] = 1;
		for (int i = 1; i < total; ++i)
			if (F[i] && result > abs(total - 2 * i))
				result = abs(total - 2 * i);
		return result;
	}
};