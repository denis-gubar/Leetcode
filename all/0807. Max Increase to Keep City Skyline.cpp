class Solution {
public:
    int maxIncreaseKeepingSkyline( vector<vector<int>>& grid ) {
        int result = 0;
        int N = grid.size();
        vector<int> A( N ), B( N );
        for (int i = 0; i < N; ++i)
        {
            A[i] = grid[i][0];
            for (int j = 0; j < N; ++j)
                A[i] = max( A[i], grid[i][j] );
        }
        for (int j = 0; j < N; ++j)
        {
            B[j] = grid[0][j];
            for (int i = 0; i < N; ++i)
                B[j] = max( B[j], grid[i][j] );
        }
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                result += min( A[i], B[j] ) - grid[i][j];
        return result;
    }
};