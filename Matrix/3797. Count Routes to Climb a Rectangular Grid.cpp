static int F[750][750][2];
static int B[751];
static int const MOD = 1'000'000'007;
class Solution {
public:
    int numberOfRoutes(vector<string>& grid, int D) {
        int const N = grid.size(), M = grid[0].size();
        long long result = 0;
        int D2 = D;
        while ((1 + D2) * (1 + D2) > D * D)
            --D2;
        auto add = [](int& x, int value)
            {
                x += value;
                if (x >= MOD)
                    x -= MOD;
                else if (x < 0)
                    x += MOD;
            };
        memset(F, 0, sizeof(F));
        for (int i = N - 1, j = 0; j < M; ++j)
            if (grid[i][j] == '.')
                F[N - 1][j][0] = 1;
        for (int i = N - 1; i >= 0; --i)
        {
            memset(B, 0, sizeof(B));
            for (int j = 0; j < M; ++j)
            {
                add(B[max(0, j - D)], F[i][j][0]);
                add(F[i][j][1], -F[i][j][0]);
                add(B[min(M, j + D + 1)], -F[i][j][0]);
            }
            for (int balance = 0, j = 0; j < M; ++j)
            {
                add(balance, B[j]);
                if (grid[i][j] == '.')
                    add(F[i][j][1], balance);
            }
            if (i == 0)
                break;
            memset(B, 0, sizeof(B));
            for (int j = 0; j < M; ++j)
                if (grid[i][j] == '.')
                {
                    int delta = 0;
                    add(delta, F[i][j][0]);
                    add(delta, F[i][j][1]);
                    add(B[max(0, j - D2)], delta);
                    add(B[min(M, j + D2 + 1)], -delta);
                }
            for (int balance = 0, j = 0; j < M; ++j)
            {
                add(balance, B[j]);
                if (grid[i - 1][j] == '.')
                    add(F[i - 1][j][0], balance);
            }
        }
        for (int i = 0, j = 0; j < M; ++j)
            for (int k = 0; k < 2; ++k)
                result += F[i][j][k];
        return result % MOD;
    }
};
