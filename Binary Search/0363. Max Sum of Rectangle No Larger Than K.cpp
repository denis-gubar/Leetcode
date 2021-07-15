class Solution {
public:
	int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
		int result = -1'000'000'000;
		int N = matrix.size(), M = matrix[0].size();
		vector<vector<int>> V(M + 1, vector<int>(N));
		for (int j = 0; j < M; ++j)
			for (int i = 0; i < N; ++i)
				V[j + 1][i] = V[j][i] + matrix[i][j];
		for (int a = 0; a < M; ++a)
			for (int b = a; b < M; ++b)
			{
				int H = 0;
				set<int> S;
				S.insert(0);
				for (int i = 0; i < N; ++i)
				{
					H += V[b + 1][i] - V[a][i];
					auto it = S.lower_bound(H - k);
					if (it != S.end())
						result = max(result, H - *it);
					S.insert(H);
				}
			}
		return result;
	}
};