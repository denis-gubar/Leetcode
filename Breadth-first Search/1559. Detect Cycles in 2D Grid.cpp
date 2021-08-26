class Solution {
public:
	bool containsCycle(vector<vector<char>>& grid) {
		int N = grid.size(), M = grid[0].size();
		vector<int>	dx{ 0, 1, 0, -1 };
		vector<int>	dy{ 1, 0, -1, 0 };
		vector<vector<bool>> visited(N, vector<bool>(M));
		for (int i = 0; i < N; ++i)
			for(int j = 0; j < M; ++j)
				if (!visited[i][j])
				{
					visited[i][j] = true;
					queue<int> Q;
					Q.push(i); Q.push(j); Q.push(-1);
					while (!Q.empty())
					{
						int x = Q.front(); Q.pop();
						int y = Q.front(); Q.pop();
						int d = Q.front(); Q.pop();
						for(int z = 0; z < 4; ++z)
							if (d < 0 || (z + 2) % 4 != d)
							{
								int nx = x + dx[z];
								int ny = y + dy[z];
								if (nx >= 0 && nx < N && ny >= 0 && ny < M && grid[x][y] == grid[nx][ny])
								{
									if (visited[nx][ny])
										return true;
									visited[nx][ny] = true;
									Q.push(nx); Q.push(ny); Q.push(z);
								}
							}
					}
				}
		return false;
	}
};