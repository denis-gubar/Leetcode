class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int result = 0;
        nums.push_back(-1);
        int N = nums.size();
        int a = 0, b = 0;
        int total = 0;
        while (b < N)
        {
            while (total & nums[b])
            {
                total &= ~(nums[a]);
                ++a;
            }
            total |= nums[b];
            result = max(result, b - a + 1);
            ++b;
        }
        return result;
    }
};
