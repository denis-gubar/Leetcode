static int F[2'000][1'001];
static int const MOD = 1'000'000'007;
class Solution {
public:
    int countOfPairs(vector<int>& nums) {
        int const N = nums.size();
        int const M = *max_element(nums.begin(), nums.end());
        long long result = 0;
        vector<int> A(N);
        A[N - 1] = nums[N - 1];
        for (int i = N - 2; i >= 0; --i)
            A[i] = min(nums[i], A[i + 1]);
        memset(F, 0, sizeof(F));
        vector<int> HWM(N, 1 << 20);
        HWM[0] = 0;
        for (int j = 0; j <= M; ++j)
            F[0][j] = 1;
        for (int i = 1; i < N; ++i)
            for (int j = HWM[i - 1]; j <= A[i - 1]; ++j)
                if (F[i - 1][j])
                {
                    int const k = nums[i - 1] - j;
                    int nk = nums[i] - j;
                    int delta = 0;
                    if (nk > k)
                        delta = nk - k;
                    for (int nj = j + delta, nk = nums[i] - nj; nj <= A[i] && nk >= 0; ++nj, --nk)
                    {
                        F[i][nj] += F[i - 1][j];
                        HWM[i] = min(HWM[i], nj);
                        if (F[i][nj] >= MOD)
                            F[i][nj] -= MOD;
                    }
                }
        for (int j = 0; j <= M; ++j)
            result += F[N - 1][j];
        return result % MOD;
    }
};
