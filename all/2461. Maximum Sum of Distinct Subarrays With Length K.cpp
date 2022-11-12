class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long result = 0;
        int N = nums.size();
        unordered_map<int, int> M;
        int nonDistinct = 0;
        long long sum = 0;
        for (int i = 0; i < k; ++i)
        {
            if (++M[nums[i]] == 2)
                ++nonDistinct;
            sum += nums[i];
        }
        if (nonDistinct == 0)
            result = sum;
        for (int i = k; i < N; ++i)
        {
            sum -= nums[i - k];
            sum += nums[i];
            if (--M[nums[i - k]] == 1)
                --nonDistinct;
            if (++M[nums[i]] == 2)
                ++nonDistinct;
            if (nonDistinct == 0)
                result = max(result, sum);
        }
        return result;
    }
};
