class Solution {
public:
    vector<int> reverseSubarrays(vector<int>& nums, int K) {
        int const N = nums.size();
        for (int i = 0, step = N / K; i < N; i += step)
            reverse(nums.begin() + i, nums.begin() + i + step);
        return nums;
    }
};
