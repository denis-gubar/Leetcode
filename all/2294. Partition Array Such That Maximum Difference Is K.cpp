class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int result = 0;
        int N = nums.size();
        sort(nums.begin(), nums.end());
        int prev = nums[0] - k - 1;
        for (int i = 0; i < N; ++i)
        {
            if (nums[i] - prev > k)
            {
                ++result;
                prev = nums[i];
            }
        }
        return result;
    }
};
