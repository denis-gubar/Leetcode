static int X[20];
class Solution {
public:
	int matrixScore(vector<vector<int>>& A) {
		int result = 0;
		int N = A.size(), M = A[0].size();
		int Z = (1 << M) - 1;
        memset(X, 0, sizeof(X));
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
				X[i] |= A[i][j] << (M - 1 - j);
		for (int i = 0; i < N; ++i)
			X[i] = max(X[i], Z - X[i]);
		int current = 0;
		for (int j = 0; j < M; ++j) 
		{
			int sum = 0;
			for (int i = 0; i < N; ++i)
				sum += (X[i] & (1 << j)) != 0;
			current += max(sum, N - sum) << j;
		}
		result = max(result, current);
		for (int i = 0; i < N; ++i)
			X[i] = Z - X[i];
		current = 0;
		for (int j = 0; j < M; ++j)
		{
			int sum = 0;
			for (int i = 0; i < N; ++i)
				sum += (X[i] & (1 << j)) != 0;
			current += max(sum, N - sum) << j;
		}
		result = max(result, current);
		return result;
	}
};

