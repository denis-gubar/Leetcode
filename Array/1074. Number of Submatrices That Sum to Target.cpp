int A[101][101];
class Solution {
public:
	int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
		int result = 0;
		int N = matrix.size(), M = matrix[0].size();
		auto get = [M](int x, int y)
		{
			return x * (M + 1) + y;
		};
        memset(A, 0, sizeof(A));		
		for (int i = 0; i < N; ++i)
		{
			int sum = 0;
			for (int j = 0; j < M; ++j)
			{
				sum += matrix[i][j];
				A[i + 1][j + 1] = A[i][j + 1] + sum;
			}
		}
		for (int a = 0; a < N; ++a)
			for (int b = a; b < N; ++b)
				for (int c = 0; c < M; ++c)
					for (int d = c; d < M; ++d)
					{
						int sum = A[b + 1][d + 1] + A[a][c] - A[b + 1][c] - A[a][d + 1];
						result += sum == target;
					}
		return result;
	}
};