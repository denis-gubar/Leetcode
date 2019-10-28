class Solution {
public:
	int uniquePathsWithObstacles( vector<vector<int>>& obstacleGrid ) {
		int result = 0;
		int m = obstacleGrid.size(), n = obstacleGrid[0].size();
		vector<vector<int>> M( m, vector<int>( n ) );
		if (obstacleGrid[0][0] == 0)
			M[0][0] = 1;
		for (int i = 0; i < m; ++i)
			for (int j = 0; j < n; ++j)
				if ( obstacleGrid[i][j] == 0)
					M[i][j] += (i > 0 ? M[i - 1][j] : 0) + (j > 0 ? M[i][j - 1] : 0);
		return M[m - 1][n - 1];
	}
};