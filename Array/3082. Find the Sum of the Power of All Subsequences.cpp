static int F[101][101][101];
static int const MOD = 1'000'000'007;
static int P[10'001];
bool static isInit = false;
static void init()
{
    if (!isInit)
    {
        isInit = true;
        P[0] = 1;
        for (int i = 0; i < 10'000; ++i)
            P[i + 1] = (P[i] << 1) % MOD;
    }
}
class Solution {
public:
    int sumOfPower(vector<int>& nums, int k) {
        init();
        int N = nums.size();
        memset(F, 0, sizeof(F));        
        F[0][0][0] = 1;
        for(int i = 0; i < N; ++i)
            for (int sum = 0; sum <= k; ++sum)
                for(int j = 0; j <= k; ++j)
                    if (F[i][sum][j] > 0)
                    {
                        F[i + 1][sum][j] = (F[i + 1][sum][j] + F[i][sum][j]) % MOD;
                        if (sum + nums[i] <= k)
                            F[i + 1][sum + nums[i]][j + 1] = (F[i + 1][sum + nums[i]][j + 1] + F[i][sum][j]) % MOD;
                    }
        long long result = 0;
        for (int j = 1; j <= k && j <= N; ++j)
            result += 1LL * F[N][k][j] * P[N - j] % MOD;
        return result % MOD;
    }
};
