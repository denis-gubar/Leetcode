class Solution {
public:
	int shortestDistance(vector<vector<int>>& grid) {
		int const INF = 1 << 25;
		int result = INF;
		int N = grid.size(), M = grid[0].size();
		vector<int> dx{ -1, 0, 1, 0 };
		vector<int> dy{ 0, -1, 0, 1 };

		int buildingCount = 0;
		int emptyCount = 0;
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
			{
				buildingCount += grid[i][j] == 1;
				emptyCount += grid[i][j] == 0;
			}
		if (buildingCount > emptyCount)
		{
			for (int i = 0; i < N; ++i)
				for (int j = 0; j < M; ++j)
					if (grid[i][j] == 0)
					{
						vector<vector<bool>> visited(N, vector<bool>(M));
						int current = 0;
						int buildingLeft = buildingCount;
						queue<int> Q;
						Q.push(i); Q.push(j); Q.push(0);
						visited[i][j] = true;
						while (!Q.empty() && buildingLeft > 0)
						{
							int x = Q.front(); Q.pop();
							int y = Q.front(); Q.pop();
							int level = Q.front(); Q.pop();
							if (grid[x][y] == 1)
							{
								current += level;
								--buildingLeft;
								continue;
							}
							for (int z = 0; z < 4; ++z)
							{
								int nx = x + dx[z];
								int ny = y + dy[z];
								if (nx >= 0 && nx < N && ny >= 0 && ny < M && !visited[nx][ny] && grid[nx][ny] != 2)
								{
									Q.push(nx); Q.push(ny); Q.push(level + 1);
									visited[nx][ny] = true;
								}
							}
						}
						if (buildingLeft == 0)
							result = min(result, current);
					}
		}
		else
		{
			vector<vector<int>> sum(N, vector<int>(M));
			vector<vector<int>> count(N, vector<int>(M));
			for (int i = 0; i < N; ++i)
				for (int j = 0; j < M; ++j)
					if (grid[i][j] == 1)
					{
						vector<vector<bool>> visited(N, vector<bool>(M));
						queue<int> Q;
						Q.push(i); Q.push(j); Q.push(0);
						visited[i][j] = true;
						while (!Q.empty())
						{
							int x = Q.front(); Q.pop();
							int y = Q.front(); Q.pop();
							int level = Q.front(); Q.pop();
							for (int z = 0; z < 4; ++z)
							{
								int nx = x + dx[z];
								int ny = y + dy[z];
								if (nx >= 0 && nx < N && ny >= 0 && ny < M && !visited[nx][ny] && grid[nx][ny] == 0)
								{
									sum[nx][ny] += level + 1;
									++count[nx][ny];
									Q.push(nx); Q.push(ny); Q.push(level + 1);
									visited[nx][ny] = true;
								}
							}
						}
					}
			for (int i = 0; i < N; ++i)
				for (int j = 0; j < M; ++j)
					if (count[i][j] == buildingCount)
						result = min(result, sum[i][j]);
		}
		if (result == INF)
			result = -1;
		return result;
	}
};