static int F[80][80][11];
class Solution {
public:
	using NodeIndex = int;
	using Distance = int;
	int minCost(vector<vector<int>>& grid, int K) {
		int const N = grid.size(), M = grid[0].size();
		memset(F, 60, sizeof(F));
		F[0][0][0] = 0;
		vector<int> I(N * M);
		iota(I.begin(), I.end(), 0);
		sort(I.begin(), I.end(), [&grid, M](int a, int b)
			{
				int ia = a / M, ja = a % M;
				int ib = b / M, jb = b % M;
				return grid[ia][ja] < grid[ib][jb];
			});
		vector<pair<int, int>> P(N * M);
		for (int i = 0, x = 0; i < N; ++i)
			for (int j = 0; j < M; ++j, ++x)
				P[x] = { I[x] / M, I[x] % M };
		vector<int> S(K + 1);
		set<pair<Distance, NodeIndex>> activeVertices;
		activeVertices.insert({ 0, 0 });
		auto add = [&activeVertices, &grid, N, M](int i, int j, int k, int f)
			{
				if (f < F[i][j][k])
				{
					int const x = k * N * M + i * M + j;
					F[i][j][k] = f;
					activeVertices.insert({ f, x });
				}
			};
		while (!activeVertices.empty())
		{
			int node = activeVertices.begin()->second;
			int const k = node / (N * M);
			int const i = node % (N * M) / M;
			int const j = node % (N * M) % M;
			activeVertices.erase(activeVertices.begin());
			if (i == N - 1 && j == M - 1)
				return F[i][j][k];
			if (i < N - 1)
				add(i + 1, j, k, F[i][j][k] + grid[i + 1][j]);
			if (j < M - 1)
				add(i, j + 1, k, F[i][j][k] + grid[i][j + 1]);
			if (k < K)
			{
				pair<int, int> const p = { i, j };
				int& HWM = S[k + 1];
				while(HWM < N * M)
				{
					pair<int, int> const pp = P[HWM];
					if (grid[p.first][p.second] < grid[pp.first][pp.second])
						break;
					add(pp.first, pp.second, k + 1, F[i][j][k]);
					++HWM;
				}
			}
		}
		return -1;
	}
};
