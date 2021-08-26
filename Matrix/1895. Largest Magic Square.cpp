class Solution {
public:
	int largestMagicSquare(vector<vector<int>>& grid) {
		int N = grid.size();
		int M = grid[0].size();
		vector<vector<int>> H(N, vector<int>(M + 1)), V(M, vector<int>(N + 1));
		for (int i = 0; i < N; ++i)
			partial_sum(grid[i].begin(), grid[i].end(), H[i].begin() + 1);
		for (int j = 0; j < M; ++j)
			for (int i = 0; i < N; ++i)
				V[j][i + 1] = V[j][i] + grid[i][j];
		auto check = [&grid, N, M, &V, &H](int length)
		{
			for (int i = 0; i + length <= N; ++i)
				for (int j = 0; j + length <= M; ++j)
				{
					int etalon = H[i][j + length] - H[i][j];
					for (int k = i + 1; k < i + length; ++k)
						if (H[k][j + length] - H[k][j] != etalon)
						{
							etalon = 0;
							break;
						}
					if (etalon == 0)
						continue;
					for (int k = j; k < j + length; ++k)
						if (V[k][i + length] - V[k][i] != etalon)
						{
							etalon = 0;
							break;
						}
					if (etalon == 0)
						continue;
					int a = 0, b = 0;
					for (int k = 0; k < length; ++k)
					{
						a += grid[i + k][j + k];
						b += grid[i + k][j + length - k - 1];
					}
					if (etalon == a && etalon == b)
						return true;
				}
			return false;
		};
		for (int b = min(N, M); b >= 1; --b)
			if (check(b))
				return b;
		return 0;
	}
};