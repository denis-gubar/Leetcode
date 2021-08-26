class Solution {
public:
	int minimumMoves(vector<vector<int>>& grid) {
		int MAX = 1'000'000;
		int N = grid.size();
		vector<int> DX{ 0, 1 };
		vector<int> DY{ 1, 0 };
		vector<vector<vector<int>>> M(2, vector<vector<int>>(N, vector<int>(N, MAX)));
		queue<int> Q;
		Q.push(0); Q.push(0); Q.push(0);
		M[0][0][0] = 0;
		while (!Q.empty())
		{
			int d = Q.front(); Q.pop();
			int x = Q.front(); Q.pop();
			int y = Q.front(); Q.pop();
			int x2 = x + DX[d];
			int y2 = y + DY[d];
			int nx = x + 1;
			int ny = y;
			int nx2 = x2 + 1;
			int ny2 = y2;
			int nd = d;
			if (nx2 < N && ny2 < N && grid[nx][ny] + grid[nx2][ny2] == 0 &&
				M[nd][nx][ny] > M[d][x][y] + 1)
			{
				M[nd][nx][ny] = M[d][x][y] + 1;
				Q.push(nd); Q.push(nx); Q.push(ny);
			}
			nx = x, ny = y + 1, nx2 = x2, ny2 = y2 + 1, nd = d;
			if (nx2 < N && ny2 < N && grid[nx][ny] + grid[nx2][ny2] == 0 &&
				M[nd][nx][ny] > M[d][x][y] + 1)
			{
				M[nd][nx][ny] = M[d][x][y] + 1;
				Q.push(nd); Q.push(nx); Q.push(ny);
			}
			if (d == 0 && x + 1 < N && grid[x + 1][y + 1] == 0)
			{
				nx = x, ny = y, nx2 = x + 1, ny2 = y, nd = 1;
				if (nx2 < N && ny2 < N && grid[nx][ny] + grid[nx2][ny2] == 0 &&
					M[nd][nx][ny] > M[d][x][y] + 1)
				{
					M[nd][nx][ny] = M[d][x][y] + 1;
					Q.push(nd); Q.push(nx); Q.push(ny);
				}
			}
			if (d == 1 && y + 1 < N && grid[x + 1][y + 1] == 0)
			{
				nx = x, ny = y, nx2 = x, ny2 = y + 1, nd = 0;
				if (nx2 < N && ny2 < N && grid[nx][ny] + grid[nx2][ny2] == 0 &&
					M[nd][nx][ny] > M[d][x][y] + 1)
				{
					M[nd][nx][ny] = M[d][x][y] + 1;
					Q.push(nd); Q.push(nx); Q.push(ny);
				}
			}
		}
		int result = M[0][N - 1][N - 2];
		if (result == MAX)
			result = -1;
		return result;
	}
};