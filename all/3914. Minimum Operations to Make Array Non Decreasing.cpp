class Solution {
public:
    long long minOperations(vector<int>& nums) {
        long long result = 0;
        int const N = nums.size();
        for (int i = 1; i < N; ++i)
            result += max(0, nums[i - 1] - nums[i]);
        return result;
    }
};
