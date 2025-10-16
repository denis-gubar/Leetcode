class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        long long result = 0;
        int const N = nums.size(), N3 = N / 3;
        sort(nums.begin(), nums.end());
        for (int i = N3; i < N; i += 2)
            result += nums[i];
        return result;
    }
};
