static long long F[100'000];
class Solution {
public:
    long long minCost(int N, int M, vector<vector<int>>& waitCost) {
		using Distance = long long;
		using NodeIndex = int;
		auto hash = [M](int x, int y)
			{
				return x * M + y;
			};
		auto update = [](long long& x, long long value)
			{
				if (x > value)
					x = value;
			};
		memset(F, 100, sizeof(F));
		F[hash(0, 0)] = (0 + 1) * (0 + 1);
		for(int x = 0; x < N; ++x)
			for (int y = 0; y < M; ++y)
			{
				long long const H = hash(x, y);
				if (!(x == 0 && y == 0 || x == N - 1 && y == M - 1))
					F[H] += waitCost[x][y];
				if (x < N - 1)
					update(F[hash(x + 1, y)], F[H] + (x + 2) * (y + 1));
				if (y < M - 1)
					update(F[hash(x, y + 1)], F[H] + (x + 1) * (y + 2));
			}
		return F[hash(N - 1, M - 1)];
    }
};
