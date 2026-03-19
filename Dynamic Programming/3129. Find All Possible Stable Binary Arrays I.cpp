static int const MOD = 1'000'000'007;
static int F[202][202][2][202];
class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        memset(F, 0, sizeof(F));
        auto add = [](int& x, int value)
            {
                x += value;
                if (x >= MOD)
                    x -= MOD;
            };
        F[0][0][0][0] = 1;
        for(int z = 0; z <= zero; ++z)
            for(int o = 0; o <= one; ++o)
                for (int l = 0; l <= limit; ++l)
                {
                    add(F[z + 1][o][0][l + 1], F[z][o][0][l]);
                    add(F[z][o + 1][1][1], F[z][o][0][l]);
                    add(F[z + 1][o][0][1], F[z][o][1][l]);
                    add(F[z][o + 1][1][l + 1], F[z][o][1][l]);
                }
        long long result = 0;
        for (int b = 0; b < 2; ++b)
            for (int l = 1; l <= limit; ++l)
                result += F[zero][one][b][l];
        return result % MOD;
    }
};
