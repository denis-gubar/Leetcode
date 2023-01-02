class Solution {
public:
    long long maximumAlternatingSubarraySum(vector<int>& nums) {
        long long result = nums[0];
        int N = nums.size();
        long long a = 0, sum = 0;
        for (int i = 0, k = 1; i < N; ++i, k = -k)
        {
            sum += k * nums[i];
            result = max(result, sum - a);
            if (k < 0)
                a = min(sum, a);
        }
        a = 0, sum = 0;
        for (int i = 1, k = 1; i < N; ++i, k = -k)
        {
            sum += k * nums[i];
            result = max(result, sum - a);
            if (k < 0)
                a = min(sum, a);
        }
        return result;
    }
};
