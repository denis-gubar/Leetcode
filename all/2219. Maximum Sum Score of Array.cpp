class Solution {
public:
    long long maximumSumScore(vector<int>& nums) {
        long long result = nums[0];
        int const N = nums.size();
        long long sum = 0;
        for (int i = 0; i < N; ++i)
        {
            sum += nums[i];
            result = max(result, sum);
        }
        sum = 0;
        for (int i = N - 1; i >= 0; --i)
        {
            sum += nums[i];
            result = max(result, sum);
        }
        return result;
    }
};
