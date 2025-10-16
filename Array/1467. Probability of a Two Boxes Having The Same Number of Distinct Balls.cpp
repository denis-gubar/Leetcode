double C(int n, int k)
{
	static const int N = 50;
	static bool isCached = false;
	static vector<vector<double>> cache = vector<vector<double>>(N + 1, vector<double>(N + 1));
	if (!isCached)
	{
		for (int i = 0; i <= N; ++i)
			cache[i][0] = cache[i][i] = 1;
		for (int i = 1; i <= N; ++i)
			for (int j = 1; j < i; ++j)
				cache[i][j] = cache[i - 1][j - 1] + cache[i - 1][j];
	}
	isCached = true;
	return n >= k && k >= 0 && n <= N ? cache[n][k] : 0;
}
class Solution {
public:
	double P(int N, int K, int n, int k)
	{
		return C(K, k) * C(N - K, n - k) / C(N, n);
	}
	void calc(vector<int> const& balls, vector<int>& A, int pos, int sum, int distinctA, int distinctB, double p)
	{
		if (pos == A.size())
		{
			if (sum != 0) return;
			count += p;
			goodCount += p * (distinctA == distinctB);
			return;
		}
		for (int i = 0; i <= sum && i <= balls[pos]; ++i)
		{
			A[pos] = i;
			calc(balls, A, pos + 1, sum - i, distinctA + (i > 0), distinctB + (i < balls[pos]),
				p * P(accumulate(balls.begin() + pos, balls.end(), 0), balls[pos], sum, i));
		}
	}
	double count;
	double goodCount;
	int total;
	double getProbability(vector<int>& balls) {
		double result = 0;
		count = goodCount = 0;
		int N = balls.size();
		total = accumulate(balls.begin(), balls.end(), 0);
		vector<int> A(N);
		calc(balls, A, 0, total / 2, 0, 0, 1.0);
		return 1.0 * goodCount / count;
	}
};