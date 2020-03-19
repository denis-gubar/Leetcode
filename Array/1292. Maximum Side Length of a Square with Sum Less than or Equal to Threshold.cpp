class Solution {
public:
	int maxSideLength(vector<vector<int>>& mat, int threshold) {
		int N = mat.size(), M = mat[0].size();
		vector<vector<int>> A;
		for (auto const& row : mat)
		{
			A.push_back({});
			partial_sum(row.begin(), row.end(), back_inserter(A.back()));
		}
		for (int i = 1; i < N; ++i)
			for (int j = 0; j < M; ++j)
				A[i][j] += A[i - 1][j];
		for (int k = min(M, N); k >= 1; --k)
		{
			for(int i = 0; i + k <= N; ++i)
				for (int j = 0; j + k <= M; ++j)
				{
					int sum = A[i + k - 1][j + k - 1] + (i > 0 && j > 0 ? A[i - 1][j - 1] : 0) - (i > 0 ? A[i - 1][j + k - 1] : 0) - (j > 0 ? A[i + k - 1][j - 1] : 0);
					if (sum <= threshold)
						return k;
				}
		}
		return 0;
	}
};