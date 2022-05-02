class Solution {
public:
	long long gridGame(vector<vector<int>>& grid) {
		int N = grid[0].size();
		long long result = 1LL << 60;
		vector<vector<long long>> A(2, vector<long long>(N + 1));
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < N; ++j)
				A[i][j + 1] = A[i][j] + grid[i][j];
		for (int j = 0; j < N; ++j)
			result = min(result, max(A[0][N] - A[0][j + 1], A[1][j] - A[1][0]));
		return result;
	}
};