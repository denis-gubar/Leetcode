class Solution {
public:
	vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
		vector<int> result;
        if (matrix.empty())
            return result;
		int N = matrix.size(), M = matrix[0].size();
        result.reserve(N * M);
		vector<vector<int>> A(N + M - 1);
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
				A[i + j].push_back(matrix[i][j]);
		for (int i = 0; i < N + M - 1; ++i)
			if (i % 2 == 0)
				reverse_copy(A[i].begin(), A[i].end(), back_inserter(result));
			else
				copy(A[i].begin(), A[i].end(), back_inserter(result));
		return result;
	}
};