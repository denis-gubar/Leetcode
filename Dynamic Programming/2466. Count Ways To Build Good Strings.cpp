static int const MOD = 1'000'000'007;
static int F[200'001];
class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        memset(F, 0, sizeof(F));
        F[0] = 1;
        auto add = [](int& x, int value)
            {
                x += value;
                if (x >= MOD)
                    x -= MOD;
            };
        for (int i = 0, end = high - min(zero, one); i <= end; ++i)
        {
            add(F[i + zero], F[i]);
            add(F[i + one], F[i]);
        }
        int result = 0;
        for (int i = low; i <= high; ++i)
            add(result, F[i]);
        return result % MOD;            
    }
};
