class Solution {
public:
	int diagonalSum(vector<vector<int>>& mat) {
		int result = 0;
		int N = mat.size();
		for (int i = 0; i < N; ++i)
			result += mat[i][N - i - 1] + mat[i][i];
		if (N % 2 == 1)
			result -= mat[N / 2][N / 2];
		return result;
	}
};