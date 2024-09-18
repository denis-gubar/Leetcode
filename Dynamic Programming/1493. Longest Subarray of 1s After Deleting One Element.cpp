class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int result = 0;
        int N = nums.size();
        int a = 0, b = 0;
        int zeroCount = 0;
        while (b < N)
        {
            zeroCount += nums[b] == 0;
            while (zeroCount > 1)
                zeroCount -= nums[a] == 0, ++a;
            result = max(result, b - a);
            ++b;
        }
        return result;
    }
};
