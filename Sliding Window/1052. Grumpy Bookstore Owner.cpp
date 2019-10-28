class Solution {
public:
	int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
		int result = 0;
		int N = customers.size();
		customers.insert(customers.begin(), 0);
		grumpy.insert(grumpy.begin(), 1);
		for (int k = 0; k < X; ++k)
			customers.push_back(0);
		for (int k = 0; k < X; ++k)
			grumpy.push_back(1);
		vector<int> C(customers);
		for (int i = 1; i <= N; ++i)
			if (!grumpy[i])
			{
				result += customers[i];
				customers[i] = 0;
			}
		vector<int> cummulative(customers);
		for (int i = 1; i <= N + 1; ++i)
			cummulative[i] += cummulative[i - 1];
		int bestDelta = 0;
		for (int start = 1; start <= N; ++start)
		{
			int delta = 0;
			for (int end = start; end <= start + X - 1; ++end)
			{
				delta = delta + customers[end];
				bestDelta = max(bestDelta, delta);
			}
		}
		return result + bestDelta;
	}
};