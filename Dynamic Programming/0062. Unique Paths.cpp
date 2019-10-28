class Solution {
public:
	int uniquePaths(int m, int n) {
		vector<vector<int>> M(m, vector<int>(n));
		M[0][0] = 1;
		for(int i = 0; i < m; ++i)
			for (int j = 0; j < n; ++j)
			{
				if (i)
					M[i][j] += M[i - 1][j];
				if (j)
					M[i][j] += M[i][j - 1];
			}
		return M.back().back();
	}
};