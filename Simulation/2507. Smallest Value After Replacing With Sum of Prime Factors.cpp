class Solution {
public:
	int calc(int N)
	{
		if (F[N] == 0)
		{
			int n = N;
			int sum = 0;
			for (int x = 2; x * x <= n; ++x)
			{
				while (n % x == 0)
					n /= x, sum += x;
			}
			if (n > 1)
				sum += n;
			if (sum != N)
				F[N] = min(calc(sum), N);
			else
				F[N] = N;
		}
		return F[N];
	}
    int smallestValue(int N) {
		F = vector<int>(1'000'000);
		return calc(N);
    }
	vector<int> F;
};
