class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        int N = nums.size();
        int result = 1'000'000'000;
        sort(nums.begin(), nums.end());
        for (int i = 1; i < N; ++i)
            result = min(result, nums[i] - nums[i - 1]);
        return result;
    }
};
