class Solution {
public:
    long long perfectPairs(vector<int>& nums) {
        long long result = 0;
        int const N = nums.size();
        for (int& x : nums)
            x = abs(x);
        sort(nums.begin(), nums.end());
        int j = 0;
        for (int i = 0; i < N; ++i)
        {
            j = max(i, j);
            while (j + 1 < N && nums[j + 1] - nums[i] <= nums[i])
                ++j;
            result += j - i;
        }
        return result;
    }
};
