class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long result = accumulate(nums.begin(), nums.end(), 0LL);
        for (int& x : nums)
            x = (x ^ k) - x;
        sort(nums.begin(), nums.end());
        for (int N = nums.size(), i = N - 1; i > 0; i -= 2)
        {
            int delta = nums[i] + nums[i - 1];
            if (delta <= 0)
                break;
            result += delta;
        }
        return result;
    }
};
