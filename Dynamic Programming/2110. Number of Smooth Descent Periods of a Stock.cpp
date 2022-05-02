class Solution {
public:
	long long calc(long long a, long long b)
	{
        long long x = b - a;
		return x * (x + 1) / 2;
	}
	long long getDescentPeriods(vector<int>& prices) {
		long long result = 0;
		int N = prices.size();
		int a = 0, b = 1;
		while (b < N)
		{
			if (prices[b] != prices[b - 1] - 1)
			{
				result += calc(a, b);
				a = b;
			}
            ++b;
		}
		result += calc(a, b);
		return result;
	}
};