class Solution {
public:
    int maxSumAfterOperation(vector<int>& nums) {
        int result = 0;
        int const N = nums.size();
        vector<int> L(N), R(N);
        for (int i = 0, sum = 0, minSum = 0; i < N; ++i)
            L[i] = sum - minSum, sum += nums[i], minSum = min(minSum, sum);
        for (int i = N - 1, sum = 0, minSum = 0; i >= 0; --i)
            R[i] = sum - minSum, sum += nums[i], minSum = min(minSum, sum);
        for (int i = 0; i < N; ++i)
            result = max(result, L[i] + nums[i] * nums[i] + R[i]);
        return result;
    }
};
