static int F[100'000];
class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        long long result = -(1LL << 60);
        int const N = nums.size();
        int prev = nums.back();
        for (int i = N - 1; i >= 0; --i)
            F[i] = min(prev, nums[i]), prev = F[i];
        long long total = 0;
        for (int i = 0; i < N - 1; ++i)
        {
            total += nums[i];
            result = max(result, total - F[i + 1]);
        }
        return result;
    }
};
