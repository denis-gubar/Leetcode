class Solution {
public:
	int minPathSum( vector<vector<int>>& grid ) {
		int result = 0;
		int m = grid.size(), n = grid[0].size();
		vector<vector<int>> M( m, vector<int>( n ) );
		M[0][0] = grid[0][0];
		for (int i = 0; i < m; ++i)
			for (int j = 0; j < n; ++j)
				if (i + j > 0)
					M[i][j] = grid[i][j] + min( (i > 0 ? M[i - 1][j] : INT_MAX), (j > 0 ? M[i][j - 1] : INT_MAX) );
		return M[m - 1][n - 1];
	}
};