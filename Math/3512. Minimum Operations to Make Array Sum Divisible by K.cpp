class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int const N = nums.size();
        int total = 0;
        for (int i = 0; i < N; ++i)
            total += nums[i] % k;
        int result = total %= k;
        return result;
    }
};
