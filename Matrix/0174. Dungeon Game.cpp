class Solution {
public:
	int calculateMinimumHP(vector<vector<int>>& dungeon) {
		int N = dungeon.size();
		if (N == 0) return 0;
		int M = dungeon[0].size();		
		long long a = 0, b = 1LL << 60;
		auto check = [&](long long m)
		{
			if (m + dungeon[0][0] < 1)
				return false;
			vector<vector<long long>> F(N, vector<long long>(M, -1));
			F[0][0] = m + dungeon[0][0];
			for(int i = 0; i < N; ++i)
				for (int j = 0; j < M; ++j)
					if (F[i][j] > 0)
					{
						if (i + 1 < N)
							F[i + 1][j] = max<long long>(F[i + 1][j], F[i][j] + dungeon[i + 1][j]);
						if (j + 1 < M)
							F[i][j + 1] = max<long long>(F[i][j + 1], F[i][j] + dungeon[i][j + 1]);
					}
			return F.back().back() > 0;
		};
		while (a + 1 < b)
		{
			long long m = (a + b) / 2;
			if (check(m))
				b = m;
			else
				a = m;
		}
		return b;
	}
};