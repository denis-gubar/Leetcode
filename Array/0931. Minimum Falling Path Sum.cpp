class Solution {
public:
	int minFallingPathSum(vector<vector<int>>& A) {
		int N = A.size();
		vector<vector<int>> M(N, vector<int>(N, 1 << 20));
		M[0] = A[0];
		for(int i = 1; i < N; ++i)
			for (int j = 0; j < N; ++j)
				for (int dx = -1; dx <= 1; ++dx)
					if (dx + j >= 0 && dx + j < N)
						M[i][j] = min(M[i][j], M[i - 1][dx + j] + A[i][j]);
		return *min_element(M[N - 1].begin(), M[N - 1].end());
	}
};