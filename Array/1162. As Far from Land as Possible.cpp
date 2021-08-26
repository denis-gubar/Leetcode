class Solution {
public:
	int maxDistance(vector<vector<int>>& grid) {
		int M = grid.size(), N = grid[0].size();
		vector<int> dx{ 0, 1, 0, -1 };
		vector<int> dy{ 1, 0, -1, 0 };
		queue<int> Q;
		for (int i = 0; i < M; ++i)
			for (int j = 0; j < N; ++j)
				if (grid[i][j] == 1)
					Q.push(i), Q.push(j);
		while (!Q.empty())
		{
			int x = Q.front(); Q.pop();
			int y = Q.front(); Q.pop();
			int t = grid[x][y];
			if (t == 1)
				t = 0;
			for (int z = 0; z < 4; ++z)
			{
				int nx = x + dx[z];
				int ny = y + dy[z];
				if (nx >= 0 && nx < M && ny >= 0 && ny < N && grid[nx][ny] == 0)
					grid[nx][ny] = t - 1, Q.push(nx), Q.push(ny);
			}
		}
		int result = grid[0][0];
		for (int i = 0; i < M; ++i)
			for (int j = 0; j < N; ++j)
				result = min(result, grid[i][j]);
        if (result == 0)
            result = 1;
		return -result;
	}
};