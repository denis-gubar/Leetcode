class Solution {
public:
	vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
		int N = mat.size(), M = mat[0].size();
		vector<vector<int>> result(N, vector<int>(M));
		vector<vector<int>> F(N, vector<int>(M));
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
			{
				F[i][j] = mat[i][j];
				if (j) F[i][j] += F[i][j - 1];
			}
		for (int j = 0; j < M; ++j)
			for (int i = 1; i < N; ++i)
				F[i][j] += F[i - 1][j];
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
			{
				result[i][j] += F[min(i + K, N - 1)][min(j + K, M - 1)];
				if (i > K && j > K)
					result[i][j] += F[i - K - 1][j - K - 1];
				if (i > K)
					result[i][j] -= F[i - K - 1][min(j + K, M - 1)];
				if (j > K)
					result[i][j] -= F[min(i + K, N - 1)][j - K - 1];
			}
		return result;
	}
};