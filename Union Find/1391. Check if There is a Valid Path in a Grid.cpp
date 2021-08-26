class Solution {
public:
	bool hasValidPath(vector<vector<int>>& grid) {
		vector<pair<int, int>> directions{ {5, 5}, {1, 3}, {0, 2}, {2, 3}, {1, 2}, {0, 3}, {0, 1} };
		vector<int> dx{ -1, 0, 1, 0 };
		vector<int> dy{  0, 1, 0, -1 };
		int N = grid.size(), M = grid[0].size();
		int x = 0, y = 0;
		queue<int> Q;
		int dirs = grid[x][y];
		Q.push(x); Q.push(y); Q.push(directions[dirs].first);
		Q.push(x); Q.push(y); Q.push(directions[dirs].second);
		while (!Q.empty())
		{
			x = Q.front(); Q.pop();
			y = Q.front(); Q.pop();
			int z = Q.front(); Q.pop();
			if (x == N - 1 && y == M - 1)
				return true;
			int nx = x + dx[z], ny = y + dy[z];
			if (nx >= 0 && nx < N && ny >= 0 && ny < M)
			{
				int ndirs = grid[nx][ny];
				if (z == (directions[ndirs].first + 2) % 4)
				{
					Q.push(nx); Q.push(ny); Q.push(directions[ndirs].second);
				}
				if (z == (directions[ndirs].second + 2) % 4)
				{
					Q.push(nx); Q.push(ny); Q.push(directions[ndirs].first);
				}
			}
		}
		return false;
	}
};