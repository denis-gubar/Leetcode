class Solution {
public:
	static const int MOD = 1000000007;
	int knightDialer(int N) {
		vector<vector<int>> connectivity(10);
		connectivity[0] = { 4, 6 };
		connectivity[1] = { 6, 8 };
		connectivity[2] = { 7, 9 };
		connectivity[3] = { 4, 8 };
		connectivity[4] = { 0, 3, 9 };
		connectivity[5] = { };
		connectivity[6] = { 0, 1, 7 };
		connectivity[7] = { 2, 6 };
		connectivity[8] = { 1, 3 };
		connectivity[9] = { 2, 4 };
		vector<long long> results(10, 1);
		for (int step = 2; step <= N; ++step)
		{
			vector<long long> next(10);
			for (int i = 0; i < 10; ++i)
				for (int j : connectivity[i])
					next[j] += results[i];
			for (int i = 0; i < 10; ++i)
				next[i] %= MOD;
			results.swap(next);
		}
		return accumulate(results.begin(), results.end(), 0LL) % MOD;
	}
};
