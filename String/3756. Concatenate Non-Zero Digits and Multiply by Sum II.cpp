static int const MOD = 1'000'000'007;
static int A[100'001];
static int P10[100'001];
static int P[320];
static int F[320];
class Solution {
public:
	vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int const N = s.size(), Q = queries.size();
		int const LENGTH = sqrt(N + 0.0) + 1;
        A[0] = 0;
		memset(F, 0, sizeof(F));
		memset(P, 0, sizeof(F));
		P10[0] = 1;
		for (int i = 0; i < N; ++i)
		{
			P10[i + 1] = P10[i] * 10LL % MOD;
			int d = s[i] - '0';
			A[i + 1] = A[i] + d;
			if (d > 0)
			{
				F[i / LENGTH] = (F[i / LENGTH] * 10LL + d) % MOD;
				++P[i / LENGTH];
			}
		}
        vector<int> result(Q);
        for (int q = 0; q < Q; ++q)
        {
            int const& L = queries[q][0];
            int const& R = queries[q][1];
			int f = 0, p = 0;
			for (int x = max(L, R / LENGTH * LENGTH); x <= R && x < N; ++x)
			{
				int d = s[x] - '0';
				if (d > 0)
					f = (f * 10LL + d) % MOD, ++p;
			}
			for (int b = R / LENGTH - 1; b >= (L + LENGTH - 1) / LENGTH; --b)
			{
				f = ((1LL * P10[p] * F[b] % MOD) + f) % MOD;
				p += P[b];
			}
			int prefix = 0;
			for (int x = L; x % LENGTH > 0 && x < R / LENGTH * LENGTH; ++x)
			{
				int d = s[x] - '0';
				if (d > 0)
					prefix = (prefix * 10LL + d) % MOD;
			}
			f = ((1LL * P10[p] * prefix % MOD) + f) % MOD;
            int sum = A[R + 1] - A[L];
			result[q] = 1LL * f * sum % MOD;
        }
        return result;
    }
};
