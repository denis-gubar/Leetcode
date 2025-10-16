class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        long long result = numeric_limits<long long>::lowest();
        int N = nums.size();
        for (int mask = 1; mask < (1 << N); ++mask)
        {
            long long current = 1;
            for (int k = 0; k < N; ++k)
                if (mask & (1 << k))
                    current *= nums[k];
            result = max(result, current);
        }
        return result;
    }
};
