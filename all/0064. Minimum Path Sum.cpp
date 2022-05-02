class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int N = grid.size(), M = grid[0].size();
        vector<vector<int>> F(N, vector<int>(M, 1 << 30));
        F[0][0] = grid[0][0];
        for(int i = 0; i < N; ++i)
            for(int j = 0; j < M; ++j)
            {
                if (i + 1 < N)
                    F[i + 1][j] = min(F[i + 1][j], F[i][j] + grid[i + 1][j]);
                if (j + 1 < M)
                    F[i][j + 1] = min(F[i][j + 1], F[i][j] + grid[i][j + 1]);
            }
        return F[N - 1][M - 1];
    }
};