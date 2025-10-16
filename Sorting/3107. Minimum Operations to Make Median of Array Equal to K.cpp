class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int K) {
        int N = nums.size();
        sort(nums.begin(), nums.end());
        long long result = 0LL;
        for (int i = 0; i < N / 2; ++i)
            if (nums[i] > K)
                result += nums[i] - K;
        result += abs(nums[N / 2] - K);
        for (int i = N / 2 + 1; i < N; ++i)
            if (nums[i] < K)
                result += K - nums[i];
        return result;
    }
};
