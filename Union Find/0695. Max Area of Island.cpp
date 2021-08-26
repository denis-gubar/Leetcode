class Solution {
public:
	int maxAreaOfIsland(vector<vector<int>>& grid) {
		int result = 0;
		int N = grid.size(), M = grid[0].size();
		vector<int> dx{ 0, 1, 0, -1 };
		vector<int> dy{ 1, 0, -1, 0 };
		for(int i = 0; i < N; ++i)
			for(int j = 0; j < M; ++j)
				if (grid[i][j])
				{
					queue<int> Q;
					Q.push(i); Q.push(j);
					grid[i][j] = 0;
					int area = 0;
					while (!Q.empty())
					{
						int x = Q.front(); Q.pop();
						int y = Q.front(); Q.pop();
						++area;
						for (int z = 0; z < 4; ++z)
						{
							int nx = x + dx[z];
							int ny = y + dy[z];
							if (nx >= 0 && nx < N && ny >= 0 && ny < M && grid[nx][ny] == 1)
							{
								Q.push(nx); Q.push(ny);
								grid[nx][ny] = 0;
							}
						}
					}
					result = max(result, area);
				}
		return result;
	}
};