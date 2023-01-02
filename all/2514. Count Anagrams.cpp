class Solution {
public:
	const int MOD = 1'000'000'007;

	int power(int x, int n)
	{
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
	int div(int x)
	{
		return power(x, MOD - 2);
	}
	int countAnagrams(string s) {
        int const MOD = 1'000'000'007;
        int N = s.size();
		vector<int> F(N + 1);
		F[0] = 1;
		for (int i = 1; i <= N; ++i)
			F[i] = 1LL * F[i - 1] * i % MOD;
		vector<int> A(26);
		s += ' ';
		int result = 1;
		int length = 0;
		for (char c : s)
		{
			int k = 1;
			if (c == ' ')
			{
				for (int i = 0; i < 26; ++i)
					k = 1LL * k * F[A[i]] % MOD;
				int x = 1LL * F[length] % MOD * div(k) % MOD;
				result = 1LL * result * x % MOD;
				length = 0;
				A.assign(26, 0);
			}
			else
			{
				++length;
				++A[c - 'a'];
			}
		}
        return result;
    }
};
