class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int const N = nums.size();
        int result = 0;
        for (int i = 1; i < N - 1; ++i)
            result += (nums[i] == (nums[i - 1] + nums[i + 1]) * 2);
        return result;
    }
};
