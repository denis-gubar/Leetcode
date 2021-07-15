class Solution {
public:
	int const MOD = 1'000'000'007;
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
	int size(vector<vector<int>> const& children, int root)
	{
		int result = 1;
		for (int next : children[root])
			result += size(children, next);
		S[root] = result;
		return result;
	}
	int calc(vector<vector<int>> const& children, int root)
	{
		if (S[root] == 1)
			return 1;
		long long result = 1;
		long long q = 1;
		int p = 0;
		for (int next : children[root])
		{
			result = result * calc(children, next) % MOD;
			q = q * F[S[next]] % MOD;
			p += S[next];
		}
		result = result * F[p] % MOD * div(q) % MOD;
		return result;
	}
	int waysToBuildRooms(vector<int>& prevRoom) {
		int N = prevRoom.size();
		vector<vector<int>> children(N);
		S = vector<int>(N);
		F = vector<int>(N + 1);
		F[0] = 1;
		for (int i = 1; i <= N; ++i)
			F[i] = 1LL * F[i - 1] * i % MOD;
		for (int i = 1; i < N; ++i)
			children[prevRoom[i]].push_back(i);
		size(children, 0);
		return calc(children, 0);
	}
	vector<int> S;
	vector<int> F;
};