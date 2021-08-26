class NumMatrix {
public:
	NumMatrix(vector<vector<int>>& matrix) {
		int N = matrix.size();
        int M = matrix[0].size();
		F = vector<vector<int>>(N, vector<int>(M));
		for (int i = 0; i < N; ++i)
		{
			int sum = 0;
			for (int j = 0; j < M; ++j)
			{
				sum += matrix[i][j];
				F[i][j] = (i > 0 ? F[i - 1][j] : 0) + sum;
			}
		}
	}

	int sumRegion(int row1, int col1, int row2, int col2) {
		return (col1 > 0 && row1 > 0 ? F[row1 - 1][col1 - 1] : 0)
            + F[row2][col2]
			- (row1 > 0 ? F[row1 - 1][col2] : 0)
			- (col1 > 0 ? F[row2][col1 - 1] : 0);
	}
	vector<vector<int>> F;
};
/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */