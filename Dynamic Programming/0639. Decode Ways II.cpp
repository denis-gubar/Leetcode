class Solution {
public:
	int numDecodings(string s) {
		int const MOD = 1'000'000'007;
		int N = s.size();
		vector<vector<int>> F(10, vector<int>(N + 2));
		F[9][1] = 1;
		for (int i = 0; i < N; ++i)
			for (int k = 1; k < 27; ++k)
			{
				int p = k / 10, d = k % 10;
				if (s[i] == '*' && d != 0 || s[i] - '0' == d)
				{
					long long total = 0;
					if (k > 9 && i > 0 && (s[i - 1] == '*' && p != 0 || s[i - 1] - '0' == p))
						for (int prev = 0; prev < 10; ++prev)
							total += F[prev][i];
					if (d > 0 && p == 0)
						for (int prev = 0; prev < 10; ++prev)
							total += F[prev][i + 1];
                    F[d][i + 2] = (F[d][i + 2] + total) % MOD;
				}
			}
		long long result = 0;
		for (int d = 0; d < 10; ++d)
			result += F[d][N + 1];
		return result % MOD;
	}
};