class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int const N = nums.size();
        nums.push_back(nums[0]);
        int result = 0;
        for (int i = 0; i < N; ++i)
            result = max(result, abs(nums[i] - nums[i + 1]));
        return result;
    }
};
