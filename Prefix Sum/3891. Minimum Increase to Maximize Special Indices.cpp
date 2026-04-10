class Solution {
public:
    long long minIncrease(vector<int>& nums) {
        long long result = 0;
        int const N = nums.size();
        if (N % 2 == 1)
        {
            for (int i = 1; i < N - 1; i += 2)
                result += max(nums[i], max(nums[i - 1], nums[i + 1]) + 1) - nums[i];
        }
        else
        {
            vector<long long> A(N), B(N + 2);
            for(int i = 1; i < N - 1; i += 2)
                A[i] = (i > 1 ? A[i - 2] : 0) + max(nums[i], max(nums[i - 1], nums[i + 1]) + 1) - nums[i];
            for (int i = N - 2; i > 0; i -= 2)
                B[i] = (i < N - 2 ? B[i + 2] : 0) + max(nums[i], max(nums[i - 1], nums[i + 1]) + 1) - nums[i];
            result = 1LL << 50;
            for (int i = -1; i < N - 1; i += 2)
                result = min(result, (i > 0 ? A[i] : 0) + B[i + 3]);
        }
        return result;
    }
};
