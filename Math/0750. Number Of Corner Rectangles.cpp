class Solution {
public:
	int countCornerRectangles(vector<vector<int>>& grid) {
		int result = 0;
		int N = grid.size(), M = grid[0].size();
		vector<int> A(M * M);
		for (int row = 0; row < N; ++row)
			for (int i = 0; i < M; ++i)
				if (grid[row][i])
					for (int j = i + 1; j < M; ++j)
						if (grid[row][j])
							++A[i * M + j];
		for (int x : A)
			result += x * (x - 1) / 2;
		return result;
	}
};