class Solution {
public:
	int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
		int MOD = 1'000'000'007;
		long long result = 0;
		int N = locations.size();
		vector<vector<int>> F(N, vector<int>(fuel + 1));
		F[start][fuel] = 1;
		vector<vector<pair<int, int>>> L(N);
		for (int V = 0; V < N; ++V)
		{
			vector<pair<int, int>>& A = L[V];
			for (int U = 0; U < N; ++U)
				if (U != V)
					A.push_back({ abs(locations[V] - locations[U]), U });
			sort(A.begin(), A.end());
		}
		for (int x = fuel; x >= 0; --x)
			for (int V = 0; V < N; ++V)
				if (F[V][x])
				{
					for (auto [length, U] : L[V])
					{
						if (length > x) break;
						F[U][x - length] += F[V][x];
						F[U][x - length] %= MOD;
					}
				}
		for (int x = 0; x <= fuel; ++x)
			result += F[finish][x];
		return result % MOD;
	}
};