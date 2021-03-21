class Solution {
public:
	int const MOD = 1'000'000'007;
	int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
		long long result = 0;
		priority_queue<pair<int, long long>> buy, sell;
		for (vector<int> const& order : orders)
		{
			int const& price = order[0];
			int amount = order[1];
			int const& orderType = order[2];
			if (orderType == 0)
			{
				while (amount > 0 && !sell.empty() && -sell.top().first <= price)
				{
					long long sellAmount = min<long long>(amount, sell.top().second);
					amount -= sellAmount;
					if (sellAmount == sell.top().second)
						sell.pop();
					else
					{
						pair<int, long long> newOrder{ sell.top().first, sell.top().second - sellAmount };
						sell.pop();
						sell.push(newOrder);
					}
				}
				if (amount > 0)
					buy.push(pair<int, long long>{price, amount});
			}
			else
			{
				while (amount > 0 && !buy.empty() && buy.top().first >= price)
				{
					long long buyAmount = min<long long>(amount, buy.top().second);
					amount -= buyAmount;
					if (buyAmount == buy.top().second)
						buy.pop();
					else
					{
						pair<int, long long> newOrder{ buy.top().first, buy.top().second - buyAmount };
						buy.pop();
						buy.push(newOrder);
					}
				}
				if (amount > 0)
					sell.push(pair<int, long long>{-price, amount});
			}
		}
		while (!sell.empty())
		{
			result += sell.top().second;
			sell.pop();
		}
		while (!buy.empty())
		{
			result += buy.top().second;
			buy.pop();
		}
		return result % MOD;
	}
};