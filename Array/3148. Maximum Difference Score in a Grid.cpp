class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int N = grid.size(), M = grid[0].size(), INF = 1 << 20;
        int result = -INF;
        vector<vector<int>> F(grid);
        for(int j = 0; j < M; ++j)
            for (int i = 0; i < N; ++i)
            {
                if (i < N - 1)
                {
                    result = max(result, max(F[i + 1][j], grid[i + 1][j]) - F[i][j]);
                    F[i + 1][j] = min({ grid[i + 1][j], F[i + 1][j], F[i][j] });
                }
                if (j < M - 1)
                {
                    result = max(result, max(F[i][j + 1], grid[i][j + 1]) - F[i][j]);
                    F[i][j + 1] = min({ grid[i][j + 1], F[i][j + 1], F[i][j] });
                }
            }
        return result;
    }
};
