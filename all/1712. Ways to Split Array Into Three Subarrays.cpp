static long long A[100'002];
static int const MOD = 1'000'000'007;
class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        long long result = 0;
        int const N = nums.size();
        A[0] = 0;
        A[N + 1] = 1LL << 40;
        for (int i = 0; i < N; ++i)
            //adding twice to avoid odd values
            A[i + 1] = A[i] + nums[i] + nums[i];
        long long const& total = A[N];
        for (int i = 0; A[i + 1] * 3 <= total && i < N - 1; ++i)
        {
            long long const& left = A[i + 1];
            auto itL = lower_bound(&A[i + 2], &A[0] + (N + 2), 2 * left);
            long long const right = total - left;
            auto itR = upper_bound(&A[i + 2], &A[0] + (N + 2), left + right / 2);
            if (itR > &A[N])
                --itR;
            if (itR > itL)
                result += itR - itL;
        }
        return result % MOD;
    }
};
