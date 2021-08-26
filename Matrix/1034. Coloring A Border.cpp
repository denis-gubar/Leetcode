class Solution {
public:
	vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
		vector<vector<int>> result(grid);
		int M = grid.size(), N = grid[0].size();
		vector<int> dx{ -1, 0, 1, 0 };
		vector<int> dy{ 0, -1, 0, 1 };
		vector<vector<int>> components(M, vector<int>(N));
		components[r0][c0] = 1;
		int componentColor = grid[r0][c0];
		queue<int> q;
		q.push(r0); q.push(c0);
		while (!q.empty())
		{
			int x = q.front(); q.pop();
			int y = q.front(); q.pop();
			for (int z = 0; z < 4; ++z)
			{
				int nx = x + dx[z];
				int ny = y + dy[z];
				if (nx >= 0 && nx < M && ny >= 0 && ny < N && !components[nx][ny] && grid[nx][ny] == componentColor)
				{
					components[nx][ny] = 1;
					q.push(nx); q.push(ny);
				}
			}
		}
		for(int i = 0; i < M; ++i)
			for(int j = 0; j < N; ++j)
				if (components[i][j])
				{
					int neighborsCount = 0;
					for (int z = 0; z < 4; ++z)
					{
						int nx = i + dx[z];
						int ny = j + dy[z];
						if (nx >= 0 && nx < M && ny >= 0 && ny < N && components[nx][ny])
							++neighborsCount;
					}
					if (neighborsCount < 4)
						result[i][j] = color;
				}
		return result;
	}
};
