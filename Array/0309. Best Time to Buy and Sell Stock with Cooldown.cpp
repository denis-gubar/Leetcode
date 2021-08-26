class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int result = 0;
		const int INF = -1'000'000'000;
		int empty = 0, have = INF, sold = INF;
		for (int p : prices)
		{
			int next_sold = have + p;
			int next_have = max(have, empty - p);
			int next_empty = max(empty, sold);
			sold = next_sold, have = next_have, empty = next_empty;
		}
		return max(sold, empty);
	}
};