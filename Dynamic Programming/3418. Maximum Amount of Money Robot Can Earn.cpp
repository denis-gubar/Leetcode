static int F[500][500][3];
class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int result = 0;
        int const N = coins.size(), M = coins[0].size();
        memset(F, -100, sizeof(F));
        F[0][0][0] = coins[0][0], F[0][0][1] = 0;
        auto update = [](int& x, int value)
            {
                if (value > x)
                    x = value;
            };
        for(int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                for (int k = 0; k < 3; ++k)
                {
                    if (i < N - 1)
                    {
                        update(F[i + 1][j][k], F[i][j][k] + coins[i + 1][j]);
                        if (k < 2)
                            update(F[i + 1][j][k + 1], F[i][j][k]);
                    }
                    if (j < M - 1)
                    {
                        update(F[i][j + 1][k], F[i][j][k] + coins[i][j + 1]);
                        if (k < 2)
                            update(F[i][j + 1][k + 1], F[i][j][k]);
                    }
                }
        return max({ F[N - 1][M - 1][0], F[N - 1][M - 1][1], F[N - 1][M - 1][2] });
    }
};
