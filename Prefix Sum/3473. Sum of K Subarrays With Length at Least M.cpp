static int F[2'001][2'002][4];
class Solution {
public:
    int maxSum(vector<int>& nums, int K, int M) {
        int const N = nums.size();
        memset(F, -61, sizeof(F));
        int const INF = F[0][1][0];
        F[0][1][0] = 0;
        auto update = [](int& x, int value)
            {
                if (x < value)
                    x = value;
            };
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j <= K; ++j)
                for (int m = 0; m <= M; ++m)
                    if (F[i][j][m] > INF)
                    {
                        if (m == M)
                        {
                            update(F[i + 1][j + 1][1], F[i][j][m] + nums[i]);
                            update(F[i + 1][j + 1][0], F[i][j][m]);
                        }
                        if (m == 0)
                            update(F[i + 1][j][m], F[i][j][m]);
                        update(F[i + 1][j][min(M, m + 1)], F[i][j][m] + nums[i]);
                    }
            update(F[i + 1][K + 1][0], F[i][K + 1][0]);
        }
        return max(F[N][K + 1][0], F[N][K][M]);
    }
};
