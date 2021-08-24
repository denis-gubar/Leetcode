class Solution {
public:
	int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int N = cells.size();
		vector<vector<int>> F(row, vector<int>(col, N + 1));
		vector<int> dx{ -1, 0, 1, 0 };
		vector<int> dy{ 0, -1, 0, 1 };		
		for (int i = 0; i < N; ++i)
			F[cells[i][0] - 1][cells[i][1] - 1] = i + 1;
		auto check = [&F, &dx, &dy, row, col, N](int limit)
		{
			vector<vector<bool>> visited(row, vector<bool>(col));
			queue<int> Q;
			for (int j = 0; j < col; ++j)
				if (F[0][j] > limit)
				{
					Q.push(0); Q.push(j);
					visited[0][j] = true;
				}
			while (!Q.empty())
			{
				int x = Q.front(); Q.pop();
				int y = Q.front(); Q.pop();
				if (x == row - 1)
					return true;
				for (int z = 0; z < 4; ++z)
				{
					int nx = x + dx[z];
					int ny = y + dy[z];
					if (nx >= 0 && nx < row & ny >= 0 && ny < col && !visited[nx][ny] && F[nx][ny] > limit)
					{
						Q.push(nx); Q.push(ny);
						visited[nx][ny] = true;
					}
				}
			}
			return false;
		};
		int a = 0, b = N;
		if (check(N))
			return N;
		while (a + 1 < b)
		{
			int m = (a + b) / 2;
			if (check(m))
				a = m;
			else
				b = m;
		}
		return a;
	}
};