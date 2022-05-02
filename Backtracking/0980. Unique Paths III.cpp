class Solution {
public:
	vector<int> const dx{ -1, 0, 1, 0 };
	vector<int> const dy{ 0, -1, 0, 1 };
	int N, M, ex, ey;
	int calc(vector<vector<bool>>& state, int x, int y, int count)
	{
		if (count == 0)
			return x == ex && y == ey;
		int result = 0;
		state[x][y] = true;
		for (int z = 0; z < 4; ++z)
		{
			int nx = x + dx[z];
			int ny = y + dy[z];
			if (nx >= 0 && nx < N && ny >= 0 && ny < M && !state[nx][ny])
				result += calc(state, nx, ny, count - 1);
		}
        state[x][y] = false;
		return result;
	}
	int uniquePathsIII(vector<vector<int>>& grid) {
		N = grid.size(), M = grid[0].size();
		vector<vector<bool>> state(N, vector<bool>(M));
		int sx = -1, sy = -1, count = 0;
		ex = -1, ey = -1;
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
			{
				switch (grid[i][j])
				{
					case 1:
						sx = i, sy = j;
						break;
					case 2:
						ex = i, ey = j;
						++count;
						break;
					case 0:
						++count;
						break;
					default:
						state[i][j] = true;
				}

			}
		return calc(state, sx, sy, count);
	}
};