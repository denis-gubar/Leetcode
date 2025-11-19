static short F[200][200][401];
class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int K) {
        int const N = grid.size(), M = grid[0].size();
        short result = -1;
        K = min(K, N + M - 1);
        memset(F, -1, sizeof(F));
        F[0][0][grid[0][0] > 0] = grid[0][0];
        auto update = [](short& x, short value)
            {
                if (x < value)
                    x = value;
            };
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                for (int k = 0, ek = i + j + 1; k <= ek; ++k)
                    if (F[i][j][k] >= 0)
                    {
                        if (i + 1 < N)
                            update(F[i + 1][j][k + (grid[i + 1][j] > 0)], F[i][j][k] + grid[i + 1][j]);
                        if (j + 1 < M)
                            update(F[i][j + 1][k + (grid[i][j + 1] > 0)], F[i][j][k] + grid[i][j + 1]);
                    }
        for (int k = 0; k <= K; ++k)
           update(result, F[N - 1][M - 1][k]);
        return result;
    }
};
