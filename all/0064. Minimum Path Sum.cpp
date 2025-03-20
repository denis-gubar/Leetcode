static int F[200][200];
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int const N = grid.size(), M = grid[0].size();
        memset(F, 1, sizeof(F));
        F[0][0] = grid[0][0];
        for(int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
            {
                if (i > 0)
                    F[i][j] = min(F[i][j], F[i - 1][j] + grid[i][j]);
                if (j > 0)
                    F[i][j] = min(F[i][j], F[i][j - 1] + grid[i][j]);
            }
        return F[N - 1][M - 1];
    }
};
