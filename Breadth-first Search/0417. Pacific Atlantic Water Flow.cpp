class Solution {
public:
	vector<int> const dx{ 0, -1, 0, 1 };
	vector<int> const dy{ -1, 0, 1, 0 };
	vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
		if (matrix.empty())
			return {};
		vector<vector<int>> result;
		int N = matrix.size(), M = matrix[0].size();
		vector<vector<char>> F(N, vector<char>(M));
		queue<int> Q;
		auto wave = [this, &Q, &F, &matrix, N, M](char color)
		{
			while (!Q.empty())
			{
				int x = Q.front(); Q.pop();
				int y = Q.front(); Q.pop();
				for (int z = 0; z < 4; ++z)
				{
					int nx = x + dx[z];
					int ny = y + dy[z];
					if (nx >= 0 && nx < N && ny >= 0 && ny < M && matrix[x][y] <= matrix[nx][ny] && (F[nx][ny] & color) == 0)
					{
						F[nx][ny] |= color;
						Q.push(nx); Q.push(ny);
					}
				}
			}
		};
		for (int i = 0; i < N; ++i)
		{
			F[i][0] |= 1;
			Q.push(i); Q.push(0);
		}
		for (int j = 1; j < M; ++j)
		{
			F[0][j] |= 1;
			Q.push(0); Q.push(j);
		}
		wave(1);
		for (int i = 0; i < N; ++i)
		{
			F[i][M - 1] |= 2;
			Q.push(i); Q.push(M - 1);
		}
		for (int j = 0; j < M - 1; ++j)
		{
			F[N - 1][j] |= 2;
			Q.push(N - 1); Q.push(j);
		}
		wave(2);
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
				if (F[i][j] == 3)
					result.push_back({ i, j });
		return result;
	}
};