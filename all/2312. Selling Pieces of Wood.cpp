class Solution {
public:
    long long sellingWood(int N, int M, vector<vector<int>>& prices) {
        vector<vector<long long>> F(N + 2, vector<long long>(M + 2));
        for (vector<int> const& P : prices)
        {
            int const& H = P[0];
            int const& W = P[1];
            int const& price = P[2];            
            F[H][W] = max(F[H][W], 1LL * price);
        }
        for (long long i = 1; i <= N; ++i)
            for (long long j = 1; j <= M; ++j)
            {
                F[i][j] = max({ F[i][j], F[i - 1][j], F[i][j - 1] });
                for (long long k = 1; k < i; ++k)
                    F[i][j] = max(F[i][j], F[i - k][j] + F[k][j]);
                for (long long k = 1; k < j; ++k)
                    F[i][j] = max(F[i][j], F[i][j - k] + F[i][k]);
            }
        return F[N][M];
    }
};
