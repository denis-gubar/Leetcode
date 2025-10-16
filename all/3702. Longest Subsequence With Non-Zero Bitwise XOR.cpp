class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int const N = nums.size();
        int total = 0, zeroCount = 0;
        for (int i = 0; i < N; ++i)
            total ^= nums[i], zeroCount += nums[i] == 0;
        if (zeroCount == N)
            return 0;
        if (total != 0)
            return N;
        return N - 1;
    }
};
