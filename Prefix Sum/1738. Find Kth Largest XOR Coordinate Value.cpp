class Solution {
public:
	int kthLargestValue(vector<vector<int>>& matrix, int k) {
		int N = matrix.size(), M = matrix[0].size();
		vector<int> A(N * M);
		vector<int> cols(M);
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
			{
				if (i > 0)
					A[i * M + j] ^= A[(i - 1) * M + j];
				A[i * M + j] ^= matrix[i][j];
				cols[j] = matrix[i][j];
				if (j > 0)
				{
					cols[j] ^= cols[j - 1];
					A[i * M + j] ^= cols[j - 1];
				}
			}
		nth_element(A.begin(), A.begin() + (k - 1), A.end(), greater<int>());
		return A[k - 1];
	}
};