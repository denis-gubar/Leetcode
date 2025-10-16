static int Prev[100'001];
static long long A[100'001];
static long long F[100'001];
class Solution {
public:
    long long minArraySum(vector<int>& nums, int K) {
        if (K == 1)
            return 0;
        int const N = nums.size();
        long long total = accumulate(nums.begin(), nums.end(), 0LL);
        memset(Prev, -1, sizeof(Prev));
        memset(F, 0, sizeof(F));
        A[0] = F[0] = 0;
        Prev[0] = 0;
        int sum = 0;
        for (int i = 0; i < N; ++i)
        {
            A[i + 1] = A[i] + nums[i];
            F[i + 1] = F[i];
            sum += nums[i];
            sum %= K;
            if (Prev[sum] >= 0)
                F[i + 1] = max(F[i + 1], F[Prev[sum]] + A[i + 1] - A[Prev[sum]]);
            Prev[sum] = i + 1;
        }
        return total - F[N];
    }
};
