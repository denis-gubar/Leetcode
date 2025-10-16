class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int result = 2;
        int const N = nums.size();
        int count = 0;
        for (int i = 2; i < N; ++i)
            if (nums[i] == nums[i - 1] + nums[i - 2])
                result = max(result, count = max(3, count + 1));
            else
                count = 0;
        return result;
    }
};
