class Solution {
public:
	int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
		int N = grid.size();
		if (grid[0][0] || grid[N - 1][N - 1])
			return -1;
		vector<vector<int>> Maze(N, vector<int>(N, N * N + 1));
		int x = N - 1, y = N - 1;
		Maze[x][y] = 1;
		queue<int> Q;
		Q.push(x); Q.push(y);
		while (!Q.empty())
		{
			x = Q.front(); Q.pop();
			y = Q.front(); Q.pop();
			if (x == 0 && y == 0)
			{
				if (Maze[0][0] == N * N + 1)
					return -1;
				return Maze[0][0];
			}
			for (int dx = -1; dx <= 1; ++dx)
			{
				int nx = x + dx;
				for (int dy = -1; dy <= 1; ++dy)
				{
					int ny = y + dy;
					if (nx >= 0 && nx < N && ny >= 0 && ny < N && !grid[nx][ny] && Maze[nx][ny] > Maze[x][y] + 1) 
					{
						Maze[nx][ny] = Maze[x][y] + 1;
						Q.push(nx); Q.push(ny);
					}
				}
			}
		}
        return -1;
	}
};