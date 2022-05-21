class Solution {
public:
    int N, M;
    bool check(vector<vector<int>> grid)
    {
        for (int i = 1; i < N; ++i)
            if (grid[i][0])
                for (int j = 0; j < M; ++j)
                    grid[i][j] = 1 - grid[i][j];
        for (int j = 1; j < M; ++j)
            if (grid[0][j])
                for (int i = 0; i < N; ++i)
                    grid[i][j] = 1 - grid[i][j];
        for (int i = 0; i < N; ++i)
            if (find(grid[i].begin(), grid[i].end(), 1) != grid[i].end())
                return false;
        return true;
    }
    bool removeOnes(vector<vector<int>>& grid) {
        N = grid.size(), M = grid[0].size();
        if (grid[0][0])
        {
            vector<vector<int>> A;
            A = grid;
            for (int j = 0; j < M; ++j)
                A[0][j] = 1 - A[0][j];
            if (check(A))
                return true;
            A[0] = grid[0];
            for (int i = 0; i < N; ++i)
                A[i][0] = 1 - A[i][0];
            return check(A);
        }
        if (check(grid))
            return true;
        vector<vector<int>> A(grid);
        for (int j = 0; j < M; ++j)
            A[0][j] = 1 - A[0][j];
        for (int i = 0; i < N; ++i)
            A[i][0] = 1 - A[i][0];
        return check(A);
    }
};
