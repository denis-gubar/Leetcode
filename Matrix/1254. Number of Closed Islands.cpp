class Solution {
public:
	void calc(queue<int>& Q, vector<vector<int>>& A)
	{
		vector<int> dx{ 0, 1, 0, -1 };
		vector<int> dy{ 1, 0, -1, 0 };
		while (!Q.empty())
		{
			int x = Q.front(); Q.pop();
			int y = Q.front(); Q.pop();
			for (int z = 0; z < 4; ++z)
			{
				int nx = dx[z] + x;
				int ny = dy[z] + y;
				if (nx < A.size() && nx >= 0 && ny < A[0].size() && ny >= 0 && A[nx][ny] == 0)
				{
					A[nx][ny] = 2;
					Q.push(nx); Q.push(ny);
				}
			}
		}
	}
	int closedIsland(vector<vector<int>>& grid) {
		int result = 0;
		vector<vector<int>> A(grid);
		int N = grid.size(), M = grid[0].size();
		queue<int> Q;
		for (int i = 0; i < N; ++i)
			if (A[i][0] == 0)
			{
				A[i][0] = 2;
				Q.push(i); Q.push(0);
                calc(Q, A);
			}
		for (int i = 0; i < N; ++i)
			if (A[i][M - 1] == 0)
			{
				A[i][M - 1] = 2;
				Q.push(i); Q.push(M - 1);
                calc(Q, A);
			}
		for (int j = 0; j < M; ++j)
			if (A[0][j] == 0)
			{
				A[0][j] = 2;
				Q.push(0); Q.push(j);
                calc(Q, A);
			}
		for (int j = 0; j < M; ++j)
			if (A[N - 1][j] == 0)
			{
				A[N - 1][j] = 2;
				Q.push(N - 1); Q.push(j);
                calc(Q, A);
			}
		for(int i = 1; i + 1 < N; ++i)
			for(int j = 1; j + 1 < M; ++j)
				if (A[i][j] == 0)
				{
					++result;
					A[i][j] = 2;
					Q.push(i); Q.push(j);
                calc(Q, A);
				}
		return result;
	}
};