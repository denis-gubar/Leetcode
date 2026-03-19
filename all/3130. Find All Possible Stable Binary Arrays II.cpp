static int const MOD = 1'000'000'007;
static int F[1'001][1'001][2];
class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        memset(F, 0, sizeof(F));
        auto add = [](int& x, int value)
            {
                x += value;
                if (x >= MOD)
                    x -= MOD;
                if (x < 0)
                    x += MOD;
            };
        for (int i = 0; i <= min(limit, max(zero, one)); ++i)
            F[i][0][0] = F[0][i][1] = 1;
        for (int z = 1; z <= zero; ++z)
            for (int o = 1; o <= one; ++o)
            {
                F[z][o][1] = F[z][o - 1][0];
                add(F[z][o][1], F[z][o - 1][1]);
                if (o > limit)
                    add(F[z][o][1], -F[z][o - limit - 1][0]);
                F[z][o][0] = F[z - 1][o][0];
                add(F[z][o][0], F[z - 1][o][1]);
                if (z > limit)
                    add(F[z][o][0], -F[z - limit - 1][o][1]);
            }
        return (F[zero][one][0] + F[zero][one][1]) % MOD;
    }
};
