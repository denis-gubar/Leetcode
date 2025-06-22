class Solution {
public:
    long long maximumProduct(vector<int>& nums, int M) {
        long long result = -(1LL << 40);
        int const N = nums.size();
        int a = nums[0], b = nums[0];
        if (M == 1)
        {
            for (int x : nums)
                result = max(result, 1LL * x * x);
            return result;
        }
        for (int i = M - 1, j = 1; i < N; ++i, ++j)
        {
            result = max(result, max(1LL * a * nums[i], 1LL * b * nums[i]));
            a = min(a, nums[j]);
            b = max(b, nums[j]);
        }
        return result;
    }
};
