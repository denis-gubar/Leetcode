class Solution {
public:
	int shortestPath(vector<vector<int>>& grid, int k) {
		int N = grid.size(), M = grid[0].size();
		vector<int> dx{ 0, 1, 0, -1 };
		vector<int> dy{ 1, 0, -1, 0 };
		vector<vector<vector<int>>> F(k + 1, vector<vector<int>>(N, vector<int>(M, 10'000)));
		F[0][0][0] = 0;
		queue<int> Q;
		Q.push(0); Q.push(0); Q.push(0);
		while (!Q.empty())
		{
			int x = Q.front(); Q.pop();
			int y = Q.front(); Q.pop();
			int obstacles = Q.front(); Q.pop();
			int length = F[obstacles][x][y];
			if (x + 1 == N && y + 1 == M)
				return length;
			for (int z = 0; z < 4; ++z)
			{
				int nx = x + dx[z], ny = y + dy[z];
				if (nx >= 0 && nx < N && ny >= 0 && ny < M &&
					obstacles + grid[nx][ny] <= k &&
					F[obstacles + grid[nx][ny]][nx][ny] > F[obstacles][x][y] + 1)
				{
					F[obstacles + grid[nx][ny]][nx][ny] = F[obstacles][x][y] + 1;
					Q.push(nx); Q.push(ny); Q.push(obstacles + grid[nx][ny]);
				}
			}
		}
		return -1;
	}
};