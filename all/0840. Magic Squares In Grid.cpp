class Solution {
public:
    bool calc( const vector<vector<int>>& A, int x, int y )
    {
        int S = A[x][y] + A[x + 1][y + 1] + A[x + 2][y + 2];
        int mask = 0;
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                if (A[x + i][y + j] < 1 || A[x + i][y + j] > 9)
                    return false;
                else
                    mask |= 1 << (A[x + i][y + j] - 1);
        if (mask != 511)
            return false;
        for (int i = 0; i < 3; ++i)
            if (A[x + i][y] + A[x + i][y + 1] + A[x + i][y + 2] != S)
                return false;
        for (int j = 0; j < 3; ++j)
            if (A[x][y + j] + A[x + 1][y + j] + A[x + 2][y + j] != S)
                return false;
        if (A[x][y] + A[x + 1][y + 1] + A[x + 2][y + 2] != S)
            return false;
        return true;
    }
    int numMagicSquaresInside( vector<vector<int>>& grid ) {
        int n = grid.size(), m = grid[0].size();
        int result = 0;
        for (int i = 0; i + 2 < n; ++i)
            for (int j = 0; j + 2 < m; ++j)
                result += calc( grid, i, j );
        return result;
    }
};