static int F[201][201][201];
static int const MOD = 1'000'000'007;
class Solution {
public:
    int subsequencePairCount(vector<int>& nums) {
        memset(F, 0, sizeof(F));
        int const N = nums.size();
        F[0][0][0] = 1;
        auto add = [](int& x, int y)
            {
                x += y;
                if (x >= MOD)
                    x -= MOD;
            };
        for(int i = 0; i < N; ++i)
            for(int j = 0; j <= 200; ++j)
                for(int k = 0; k <= 200; ++k)
                    if (F[i][j][k])
                    {
                        add(F[i + 1][j][k], F[i][j][k]);
                        add(F[i + 1][j == 0 ? nums[i] : gcd(j, nums[i])][k], F[i][j][k]);
                        add(F[i + 1][j][k == 0 ? nums[i] : gcd(k, nums[i])], F[i][j][k]);
                    }
        long long result = 0;
        for (int k = 1; k <= 200; ++k)
            result += F[N][k][k];
        return result % MOD;
    }
};
