class Solution {
public:
	vector<vector<int>> imageSmoother(vector<vector<int>>& A) {
		int N = A.size(), M = A[0].size();
		vector<vector<int>> result(N, vector<int>(M));
		for(int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
			{
				int sum = 0, count = 0;
				for (int a = max(0, i - 1); a <= min(N - 1, i + 1); ++a)
					for (int b = max(0, j - 1); b <= min(M - 1, j + 1); ++b)
						++count, sum += A[a][b];
				result[i][j] = sum / count;
			}
		return result;
	}
};