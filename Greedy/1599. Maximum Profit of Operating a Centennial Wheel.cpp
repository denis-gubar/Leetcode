class Solution {
public:
	int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
		long long result = -1, best = 0, current = 0, q = 0, i = 0;
		for (int x : customers)
		{
			++i;
			q += x;
			long long delta = min(4LL, q);
			q -= delta;
			current += delta * boardingCost;
			current -= runningCost;
			if (best < current)
				best = current, result = i;
		}
		long long delta = q / 4;
		i += delta;
		q %= 4;
		current += 4 * delta * boardingCost;
		current -= delta * runningCost;
		if (best < current)
			best = current, result = i;
		if (q)
		{
			++i;
			current += q * boardingCost;
			current -= runningCost;
			if (best < current)
				best = current, result = i;
		}
		return result;
	}
};