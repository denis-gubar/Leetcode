class Solution {
public:
	int maxProfit(vector<int>& prices, int fee) {
		int const INF = -2'000'000'000;
		int empty = 0, have = INF;
		for (int p : prices)
		{
			int next_empty = max(empty, have + p - fee);
			int next_have = max(have, empty - p);
			empty = next_empty, have = next_have;
		}
		return empty;
	}
};