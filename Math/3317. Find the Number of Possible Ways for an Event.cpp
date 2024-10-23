static int const MOD = 1'000'000'007;
static int S[1'001][1'001];
static int F[1'001];
static bool isInit = false;
static int power(int x, int n)
{
	if (n == 0)
		return 1;
	if (n == 1)
		return x;
	long long result = x;
	long long extra = 1;
	while (n > 1)
	{
		if (n % 2)
		{
			extra *= result;
			extra %= MOD;
		}
		result *= result;
		result %= MOD;
		n /= 2;
	}
	return result * extra % MOD;
}
static int div(int x)
{
	return power(x, MOD - 2);
}
static void init()
{
	if (!isInit)
	{
		isInit = true;
		F[0] = 1;
		for (int i = 1; i <= 1'000; ++i)
			F[i] = 1LL * i * F[i - 1] % MOD;
		memset(S, 0, sizeof(S));
		for (int i = 1; i <= 1'000; ++i)
			for (int j = 1; j <= 1'000; ++j)
			{
				if (i == j)
					S[i][j] = 1;
				else if (i > j)
					S[i][j] = (1LL * j * S[i - 1][j] + S[i - 1][j - 1]) % MOD;
			}
	}
}
class Solution {
public:
    int numberOfWays(int N, int X, int Y) {
		init();
		long long result = 0;
		for (int M = 1; M <= X && M <= N; ++M)
			result += 1LL * S[N][M] * F[X] % MOD * div(F[X - M]) % MOD * power(Y, M) % MOD;
		return result % MOD;
    }
};
