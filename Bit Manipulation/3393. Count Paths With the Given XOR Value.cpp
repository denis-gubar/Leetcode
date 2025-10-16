static int const MOD = 1'000'000'007;
static int F[300][300][16];
class Solution {
public:
    int countPathsWithXorValue(vector<vector<int>>& grid, int K) {
        int const N = grid.size(), M = grid[0].size();
        memset(F, -1, sizeof(F));
        array const dx{ 0, 1 };
        array const dy{ 1, 0 };
        F[0][0][grid[0][0]] = 1;
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                for(int k = 0; k < 16; ++k)
                    if (F[i][j][k] >= 0)
                    {
                        for (int z = 0; z < 2; ++z)
                        {
                            int ni = i + dx[z];
                            int nj = j + dy[z];
                            if (ni < N && nj < M)
                                F[ni][nj][grid[ni][nj] ^ k] = (max(F[ni][nj][grid[ni][nj] ^ k], 0) + F[i][j][k]) % MOD;
                        }
                    }
        return max(F[N - 1][M - 1][K], 0);
    }
};
