class Solution {
public:
	int minFallingPathSum(vector<vector<int>>& arr) {
		int result = 0;
		int N = arr.size();
		if (N == 1) return arr[0][0];
		vector<vector<int>> F(2, vector<int>(N));
		for (int i = 0; i < N; ++i)
		{
			vector<pair<int, int>> A(N);
			for (int j = 0; j < N; ++j)
				A[j] = { F[i % 2][j], j };
			partial_sort(A.begin(), A.begin() + 2, A.end());
			for (int j = 0; j < N; ++j)
			{
				int M = A[0].first;
				if (A[0].second == j)
					M = A[1].first;
				F[(i + 1) % 2][j] = arr[i][j] + M;
			}
		}
		return *min_element(F[N % 2].begin(), F[N % 2].end());
	}
};