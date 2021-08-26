class Solution {
public:
	vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
		int N = rowSum.size(), M = colSum.size();
		vector<vector<int>> result(N, vector<int>(M));
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
			{
				result[i][j] = min(rowSum[i], colSum[j]);
				rowSum[i] -= result[i][j];
				colSum[j] -= result[i][j];
			}
		return result;
	}
};