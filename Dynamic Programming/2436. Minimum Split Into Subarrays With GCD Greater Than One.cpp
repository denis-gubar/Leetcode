class Solution {
public:
    int minimumSplits(vector<int>& nums) {
        int result = 1;
        int prev = nums[0];
        for (int x : nums)
            if (int const k = gcd(x, prev); k > 1)
                prev = k;
            else
                prev = x, ++result;
        return result;
    }
};
