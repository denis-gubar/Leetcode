class Solution {
public:
	int numSubmat(vector<vector<int>>& mat) {
		int result = 0;
		int N = mat.size(), M = mat[0].size();
		vector<vector<int>> A(N, vector<int>(M));
		for(int i = 0; i < N; ++i)
			for (int j = M - 1; j >= 0; --j)
			{
				A[i][j] += mat[i][j];
				if (A[i][j] && j + 1 < M)
					A[i][j] += A[i][j + 1];
			}
		for(int i = 0; i < N; ++i)
			for(int j = 0; j < M; ++j)
				if (mat[i][j])
				{
					int width = M;
					for (int x = i; x < N && mat[x][j]; ++x)
					{
						width = min(width, A[x][j]);
						result += width;
					}
				}
		return result;
	}
};