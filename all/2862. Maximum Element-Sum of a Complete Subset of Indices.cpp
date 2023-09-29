class Solution {
public:
    long long maximumSum(vector<int>& nums) {
        long long result = 0;
        int N = nums.size();        
        for (int b = 1; b <= N; ++b)
        {
            long long current = 0;
            for (int x = 1; b * x * x <= N; ++x)
                current += nums[b * x * x - 1];
            result = max(result, current);
        }        
        return result;
    }
};
