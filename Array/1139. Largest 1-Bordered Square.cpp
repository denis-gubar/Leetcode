class Solution {
public:
	int largest1BorderedSquare(vector<vector<int>>& grid) {
		int N = grid.size(), M = grid[0].size();
		vector<vector<pair<int, int>>> H(N), V(M);
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
				if (grid[i][j] == 1)
				{
					if (H[i].empty() || grid[i][j - 1] == 0)
						H[i].push_back({ j, j });
					else
						++H[i].back().second;
				}
		for (int j = 0; j < M; ++j)
			for (int i = 0; i < N; ++i)
				if (grid[i][j] == 1)
				{
					if (V[j].empty() || grid[i - 1][j] == 0)
						V[j].push_back({ i, i });
					else
						++V[j].back().second;
				}
		for (int result = min(N, M); result > 0; --result)
			for (int x = 0; x + result <= N; ++x)
				for (int y = 0; y + result <= M; ++y)
				{
					auto it = lower_bound(H[x].begin(), H[x].end(), pair<int, int>{ y + 1, y + 1 });
					if (it == H[x].begin())
						continue;
					--it;
					if (y + result - 1 > it->second)
						continue;
					it = lower_bound(H[x + result - 1].begin(), H[x + result - 1].end(), pair<int, int>{ y + 1, y + 1 });
					if (it == H[x + result - 1].begin())
						continue;
					--it;
					if (y + result - 1 > it->second)
						continue;
					it = lower_bound(V[y].begin(), V[y].end(), pair<int, int>{x + 1, x + 1});
					if (it == V[y].begin())
						continue;
					--it;
					if (x + result - 1 > it->second)
						continue;
					it = lower_bound(V[y + result - 1].begin(), V[y + result - 1].end(), pair<int, int>{x + 1, x + 1});
					if (it == V[y + result - 1].begin())
						continue;
					--it;
					if (x + result - 1 > it->second)
						continue;
					return result * result;
				}
		return 0;
	}
};