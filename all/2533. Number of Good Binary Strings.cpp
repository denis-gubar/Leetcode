static int const MOD = 1'000'000'007;
static int F[100'002];
class Solution {
public:
    int goodBinaryStrings(int minLength, int maxLength, int oneGroup, int zeroGroup) {
        long long result = 0;
        memset(F, 0, sizeof(F));
        F[0] = 1;
        auto add = [](int& x, int y) -> void
            {
                x += y;
                if (x >= MOD)
                    x -= MOD;
            };
        for (int i = 0; i < maxLength; ++i)
        {
            add(F[min(maxLength + 1, i + oneGroup)], F[i]);
            add(F[min(maxLength + 1, i + zeroGroup)], F[i]);
        }
        for (int i = minLength; i <= maxLength; ++i)
            result += F[i];
        return result % MOD;
    }
};
