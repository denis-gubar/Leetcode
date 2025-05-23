static short F[100][20];
class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int const N = costs.size(), K = costs[0].size();
        memset(F, 60, sizeof(F));
        for (int j = 0; j < K; ++j)
            F[0][j] = costs[0][j];
        for (int i = 1; i < N; ++i)
            for (int j = 0; j < K; ++j)
                for (int nj = 0; nj < K; ++nj)
                    if (j != nj)
                        F[i][nj] = min<short>(F[i][nj], F[i - 1][j] + costs[i][nj]);
        return *min_element(&F[N - 1][0], &F[N - 1][0] + K);
    }
};
