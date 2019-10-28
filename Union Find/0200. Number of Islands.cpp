class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		int result = 0;
		int n = grid.size();
		if (!n)
			return 0;
		int m = grid[0].size();
		vector<vector<bool>> visited(n, vector<bool>(m));
		vector<int> dx = { 0, 1, 0, -1 };
		vector<int> dy = { 1, 0, -1, 0 };
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < m; ++j)
				if (!visited[i][j] && grid[i][j] == '1')
				{
					++result;
					visited[i][j] = true;
					queue<int> Q;
					Q.push(i); Q.push(j);
					while (!Q.empty())
					{
						int x = Q.front(); Q.pop();
						int y = Q.front(); Q.pop();
						for (int z = 0; z < 4; ++z)
						{
							int nx = x + dx[z], ny = y + dy[z];
							if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && grid[nx][ny] == '1')
							{
								visited[nx][ny] = true;
								Q.push(nx); Q.push(ny);
							}
						}
					}
				}
		return result;
	}
};