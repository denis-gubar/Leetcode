class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int result = 0;
        nums.resize(unique(nums.begin(), nums.end()) - nums.begin());
        int N = nums.size();
        for (int i = 1; i < N - 1; ++i)
            if (nums[i - 1] < nums[i] && nums[i] > nums[i + 1] ||
                nums[i - 1] > nums[i] && nums[i] < nums[i + 1])
                ++result;
        return result;
    }
};
