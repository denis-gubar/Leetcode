class Solution {
public:
	int longestIncreasingPath(vector<vector<int>>& matrix) {
		if (matrix.empty()) return 0;
		int result = 1;
		int N = matrix.size(), M = matrix[0].size();
		vector<int>	dx{ 0, 1, 0, -1 };
		vector<int>	dy{ 1, 0, -1, 0 };
		vector<vector<int>> A;
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
				A.push_back({ matrix[i][j], i, j });
		sort(A.begin(), A.end());
		vector<vector<int>> F(N, vector<int>(M));
		for (int i = 0; i < A.size(); ++i)
		{
			int const& weight = A[i][0];
			int const& x = A[i][1];
			int const& y = A[i][2];
			if (F[x][y])
				continue;
            F[x][y] = 1;
			for (int z = 0; z < 4; ++z)
			{
				int nx = x + dx[z];
				int ny = y + dy[z];
				if (nx >= 0 && nx < N && ny >= 0 && ny < M && weight > matrix[nx][ny])
					F[x][y] = max(F[x][y], F[nx][ny] + 1);
			}
			result = max(result, F[x][y]);
		}
		return result;
	}
};