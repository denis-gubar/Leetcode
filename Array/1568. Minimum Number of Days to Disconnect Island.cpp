class Solution {
public:
	int minDays(vector<vector<int>>& grid) {
		int N = grid.size(), M = grid[0].size();
		vector<vector<bool>> visited(N, vector<bool>(M));
		vector<int>	dx{ 0, 1, 0, -1 };
		vector<int>	dy{ 1, 0, -1, 0 };
		int total = 0;
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
				total += grid[i][j];
		int count = 0;
		for(int i = 0; i < N; ++i)
			for(int j = 0; j < M; ++j)
				if (grid[i][j] && !visited[i][j])
				{
                    ++count;
					visited[i][j] = true;
					queue<int> Q;
					Q.push(i); Q.push(j);
					while (!Q.empty())
					{
						int x = Q.front(); Q.pop();
						int y = Q.front(); Q.pop();
						for (int z = 0; z < 4; ++z)
						{
							int nx = x + dx[z];
							int ny = y + dy[z];
							if (nx >= 0 && nx < N && ny >= 0 && ny < M && grid[nx][ny] && !visited[nx][ny])
							{
                                visited[nx][ny] = true;
								Q.push(nx); Q.push(ny);
							}
						}
					}
				}
		if (count != 1)
			return 0;
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
				if (grid[i][j])
				{
					vector<pair<int, int>> neigbors;
					for (int z = 0; z < 4; ++z)
					{
						int nx = i + dx[z];
						int ny = j + dy[z];
						if (nx >= 0 && nx < N && ny >= 0 && ny < M && grid[nx][ny])
						    neigbors.push_back({ nx, ny });
					}
					if (neigbors.size() == 0)
						return 1;
					grid[i][j] = 0;
					int count = 2;
					visited = vector<vector<bool>>(N, vector<bool>(M));
					queue<int> Q;
					int x = neigbors[0].first;
					int y = neigbors[0].second;
					Q.push(x); Q.push(y);
					visited[x][y] = true;
					while (!Q.empty())
					{
						x = Q.front(); Q.pop();
						y = Q.front(); Q.pop();
						for (int z = 0; z < 4; ++z)
						{
							int nx = x + dx[z];
							int ny = y + dy[z];
							if (nx >= 0 && nx < N && ny >= 0 && ny < M && grid[nx][ny] && !visited[nx][ny])
							{
								visited[nx][ny] = true;
								++count;
								Q.push(nx); Q.push(ny);
							}
						}
					}
					if (count != total)
						return 1;
					grid[i][j] = 1;
				}
		return 2;
	}
};