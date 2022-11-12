class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int N = grid.size(), M = grid[0].size();
        constexpr int MOD = 1'000'000'007;
        vector<vector<vector<int>>> F(k, vector<vector<int>>(N, vector<int>(M)));
        F[grid[0][0] % k][0][0] = 1;
        for(int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                for (int z = 0; z < k; ++z)
                {
                    if (i + 1 < N)
                        F[(z + grid[i + 1][j]) % k][i + 1][j] = (F[(z + grid[i + 1][j]) % k][i + 1][j]
                            + F[z][i][j]) % MOD;
                    if (j + 1 < M)
                        F[(z + grid[i][j + 1]) % k][i][j + 1] = (F[(z + grid[i][j + 1]) % k][i][j + 1]
                            + F[z][i][j]) % MOD;
                }
        return F[0][N - 1][M - 1];
    }
};
