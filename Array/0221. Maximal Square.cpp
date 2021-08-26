class Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		int result = 0;
		int N = matrix.size(), M = N ? matrix[0].size() : 0;
		if (N == 0 || M == 0)
			return 0;
		vector<vector<int>> A(N, vector<int>(M));
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
				if (matrix[i][j] == '1')
                {
					A[i][j] = 1 + min({i ? A[i - 1][j] : 0, j ? A[i][j - 1] : 0, i && j ? A[i - 1][j - 1] : 0});
                    result = max(result, A[i][j]);
                }
		return result * result;
	}
};