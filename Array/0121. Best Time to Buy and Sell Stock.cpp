class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() < 2)
			return 0;
		int result = 0;
		int currentPrice = prices[0];
		for (int price : prices)
			if (price > currentPrice)
				result = max(result, price - currentPrice);
			else
				currentPrice = price;
		return result;
	}
};