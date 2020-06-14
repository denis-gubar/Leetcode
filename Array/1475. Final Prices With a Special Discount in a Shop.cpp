class Solution {
public:
	vector<int> finalPrices(vector<int>& prices) {
		vector<int> result;
		for (int i = 0; i < prices.size(); ++i)
		{
			int x = prices[i];
			int best = 10'000;
			for (int j = i + 1; j < prices.size(); ++j)
				if (best > prices[j] && prices[j] <= prices[i])
				{
					best = prices[j];
					break;
				}
			if (best < 10'000)
				x -= best;
			result.push_back(x);
		}
		return result;
	}
};