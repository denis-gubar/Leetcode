class Solution {
public:
	int maxUncrossedLines(vector<int>& A, vector<int>& B) {
		int N = A.size(), M = B.size();
		vector<vector<int>> F(N + 1, vector<int>(M + 1));
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
				F[i + 1][j + 1] = max({F[i][j + 1], F[i + 1][j], F[i][j] + (A[i] == B[j])});
		return F[N][M];
	}
};