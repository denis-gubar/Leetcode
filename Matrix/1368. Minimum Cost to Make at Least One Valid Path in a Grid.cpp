static int F[100][100];
class Solution {
public:
	int minCost(vector<vector<int>>& grid) {
		int const N = grid.size(), M = grid[0].size();
		memset(F, 1, sizeof(F));
		vector<int> dx{ 0, 0, 0, 1, -1 };
		vector<int> dy{ 0, 1, -1, 0, 0 };
		F[0][0] = 0;
		queue<int> Q;
		Q.push(0); Q.push(0);
		while (!Q.empty())
		{
			int x = Q.front(); Q.pop();
			int y = Q.front(); Q.pop();
			int const& cost = F[x][y];
			int const& dir = grid[x][y];
			for (int z = 1; z < 5; ++z)
			{
				int nx = x + dx[z];
				int ny = y + dy[z];
				if (nx >= 0 && nx < N && ny >= 0 && ny < M)
				{
					int ncost = cost + (z != dir);
					if (F[nx][ny] > ncost)
					{
						F[nx][ny] = ncost;
						Q.push(nx); Q.push(ny);
					}
				}
			}
		}
		return F[N - 1][M - 1];
	}
};