class Solution {
public:
	int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
		int N = maze.size(), M = maze[0].size();
		int const INF = 1 << 30;
		vector<vector<int>> F(N, vector<int>(M, INF));
		vector<int> dx{ 0, -1, 0, 1 };
		vector<int> dy{ -1, 0, 1, 0 };
		queue<int> Q;
		Q.push(entrance[0]); Q.push(entrance[1]);
		F[entrance[0]][entrance[1]] = 0;
		while (!Q.empty())
		{
			int x = Q.front(); Q.pop();
			int y = Q.front(); Q.pop();
			for (int z = 0; z < 4; ++z)
			{
				int nx = x + dx[z];
				int ny = y + dy[z];
				if (nx == -1 || nx == N || ny == -1 || ny == M)
				{
					if (F[x][y] != 0)
                    {
						return F[x][y];
                    }
				}
				else if (F[nx][ny] == INF && maze[nx][ny] == '.')
				{
					F[nx][ny] = F[x][y] + 1;
					Q.push(nx); Q.push(ny);
				}
			}
		}
		return -1;
	}
};