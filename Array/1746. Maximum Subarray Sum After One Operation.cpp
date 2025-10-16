static int A[100'000];
class Solution {
public:
    int maxSumAfterOperation(vector<int>& nums) {
        int result = 0;
        int const N = nums.size();
        for (int i = 0, sum = 0, minSum = 0; i < N; ++i)
            A[i] = sum - minSum, sum += nums[i], minSum = min(minSum, sum);
        for (int i = N - 1, sum = 0, minSum = 0; i >= 0; --i)
            A[i] += sum - minSum, sum += nums[i], minSum = min(minSum, sum);
        for (int i = 0; i < N; ++i)
            result = max(result, A[i] + nums[i] * nums[i]);
        return result;
    }
};
