static int const MOD = 1'000'000'007;
static int F[26][2];
class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        long long result = 0;
        memset(F, 0, sizeof(F));
        for (char c : s)
            ++F[c - 'a'][0];
        auto add = [](int& x, int y)
            {
                x += y;
                if (x >= MOD)
                    x -= MOD;
            };
        for (int k = 0; k < t; ++k)
        {
            for(int c = 0; c < 25; ++c)
                F[c + 1][1 - k % 2] = F[c][k % 2];
            F[0][1 - k % 2] = F[25][k % 2];
            add(F[1][1 - k % 2], F[25][k % 2]);
        }
        for (int c = 0; c < 26; ++c)
            result += F[c][t % 2];
        return result % MOD;
    }
};
