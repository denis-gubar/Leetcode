class Solution {
public:
	int maximalRectangle( vector<vector<char>>& matrix ) {
		if (matrix.empty())
			return 0;
		int result = 0;
		int m = matrix.size(), n = matrix[0].size();
		vector<vector<int>> X( m, vector<int>( n ) ), Y( m, vector<int>( n ) );
		for (int i = 0; i < m; ++i)
			for (int j = 0; j < n; ++j)
				if (matrix[i][j] == '1')
				{
					X[i][j] = 1 + (i > 0 ? X[i - 1][j] : 0);
					Y[i][j] = 1 + (j > 0 ? Y[i][j - 1] : 0);
				}
		for (int i = 0; i < m; ++i)
			for (int j = 0; j < n; ++j)
				if (result < X[i][j] * Y[i][j])
				{
					int x = X[i][j], y = Y[i][j];
					int a = x;
					for (int k = 1; k <= y && a * y > result; ++k)
					{
						a = min( a, X[i][j - k + 1] );
						result = max( result, a * k );
					}
					int b = y;
					for (int k = 1; k <= x && b * x > result; ++k)
					{
						b = min( b, Y[i - k + 1][j] );
						result = max( result, b * k );
					}
				}
		return result;
	}
};