static int F[102][1 << 10];
class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int const N = grid.size(), M = grid[0].size();
        memset(F, -1, sizeof(F));
        F[101][(1 << N) - 1] = 0;
        vector<int> values(101);
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                values[grid[i][j]] |= 1 << i;
        for(int i = 100; i >= 0; --i)
            for (int mask = 0; mask < (1 << N); ++mask)
                if (F[i + 1][mask] >= 0)
                {
                    F[i][mask] = F[i + 1][mask];
                    int x = mask & values[i];
                    for(int k = 0; k < N; ++k)
                        if (x & (1 << k))
                            F[i][mask ^ (1 << k)] = max(F[i][mask ^ (1 << k)], F[i + 1][mask] + i);
                }
        return *max_element(&F[0][0], &F[0][0] + (1 << N));
    }
};
