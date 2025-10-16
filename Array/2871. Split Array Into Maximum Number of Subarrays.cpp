class Solution {
public:
    int maxSubarrays(vector<int>& nums) {
        int N = nums.size();
        int total = nums[0];
        for (int x : nums)
            total &= x;
        if (total > 0)
            return 1;
        int result = 0;
        total = nums[0];
        for (int x : nums)
        {
            total &= x;
            if (total == 0)
            {
                ++result;
                total = (1 << 30) - 1;
            }
        }
        return result;
    }
};
