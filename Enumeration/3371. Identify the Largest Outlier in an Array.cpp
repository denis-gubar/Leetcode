class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int const N = nums.size();
        int result = 0;
        int total = accumulate(nums.begin(), nums.end(), 0);
        sort(nums.begin(), nums.end());
        unordered_map<int, int> M;
        for (int x : nums)
            ++M[x];
        for (int i = N - 1; i >= 0; --i)
        {
            int const sum = total - nums[i];
            if (sum % 2 != 0)
                continue;
            if (M[sum / 2] > (nums[i] == sum / 2))
                return nums[i];
        }
        return -1'001;
    }
};
